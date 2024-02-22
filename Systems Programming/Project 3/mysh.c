#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <glob.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 100

void execute_command(char *argv[]);
void execute_pipe_command(char *args1[], char *args2[]);
void expand_wildcards(char *arg, char **argv, int *argc);
void parse_and_execute(char *command);
void interactive_mode(void);  
void batch_mode(const char *filename);

int outputfd = -1;
int inputfd = -1;
int batchMode = 0;
int batch_fd = -1;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        batch_mode(argv[1]);
    } else {
        interactive_mode();
    }
    return 0;
}

void execute_command(char *argv[]) {
    int saved_stdout;
    int saved_stdin;

    if(argv[0] == NULL) {
        return;
    }

    if(outputfd != -1) {
        saved_stdout = dup(STDOUT_FILENO);
        dup2(outputfd, STDOUT_FILENO);
        close(outputfd);
    }

    if(inputfd != -1) {
        saved_stdin = dup(STDIN_FILENO);
        dup2(inputfd, STDIN_FILENO);
        close(inputfd);
    }

    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL || argv[2] != NULL) {
            fprintf(stderr, "cd: Error Number of Parameters\n");
        } else if (chdir(argv[1]) != 0) {
            perror("cd");
        }
    } 
    else if (strcmp(argv[0], "pwd") == 0) {
        char cwd[MAX_COMMAND_LENGTH];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } 
        else {
            perror("pwd");
        }
    } 
    else {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        }
        else if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                    //perror("execvp");
                    printf("%s: command not found.\n", argv[0]);
                    //exit(EXIT_FAILURE);
                }
            }
        else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    if(outputfd != -1) {
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
        outputfd = -1;
    }

    if(inputfd != -1) {
        dup2(saved_stdin, STDIN_FILENO);
        close(saved_stdin);
        inputfd = -1;
    }
}

void printArgs(char* args[]) {
    printf("TOKENS: \n");
    int i = 0;
    while(args[i] != NULL) {
        printf("%s\n", args[i]);
        i++;
    }
    printf("--------\n");
}

 void execute_pipe_command(char *args1[], char *args2[]) {
    int pipe_fds[2];
    pid_t pid1, pid2;

    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == 0) {
        // first child
        close(pipe_fds[0]); 
        dup2(pipe_fds[1], STDOUT_FILENO);   
        close(pipe_fds[1]);

        execvp(args1[0], args1);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 == 0) {
        // second child
        close(pipe_fds[1]); 
        dup2(pipe_fds[0], STDIN_FILENO);  
        close(pipe_fds[0]);

        execvp(args2[0], args2);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // father
    close(pipe_fds[0]);
    close(pipe_fds[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void expand_wildcards(char *arg, char **argv, int *argc) {
    glob_t glob_result;
    size_t i;  

    if (glob(arg, GLOB_NOCHECK | GLOB_TILDE, NULL, &glob_result) == 0) {
        for (i = 0; i < glob_result.gl_pathc && *argc < MAX_ARGS - 1; i++) {
            argv[(*argc)++] = strdup(glob_result.gl_pathv[i]);
        }
    }
    globfree(&glob_result);
}

void conditional_mode(char* command) {
    char *open = strstr(command, "[");
    char *close = strstr(command, "]");
    
    if (open != NULL && close != NULL) {
        size_t length = close - open + 1;
        
        char *equation = malloc(length + 1);
        strncpy(equation, open, length);
        equation[length] = '\0';

        int result = system(equation); // 0 if true, false otherwise.
        int status = WEXITSTATUS(result);
        if(status == 127) {
            return;
        }
        // printf("RESULT: %d\n", result);
        // printf("STATUS: %d\n", status);

        char tempCommand[MAX_COMMAND_LENGTH];
        char* trueBranch;
        char* elseBranch;
        int isThen = 0;
        int isElse = 0;

        if(strstr(command, "then") > close) {
            isThen = 1;
        }

        while(1) {
            if(batchMode == 0) {
                printf("> ");
            }
            if(!fgets(tempCommand, MAX_COMMAND_LENGTH, stdin)) {
                break;
            }

            tempCommand[strcspn(tempCommand, "\n")] = 0;

            if(strcmp(tempCommand, "then") == 0) {
                isThen = 1;
            }
            else if(strcmp(tempCommand, "else") == 0) {
                isElse = 1;
            }
            else if(strcmp(tempCommand, "fi") == 0) {
                if(result == 0) {
                    parse_and_execute(trueBranch);
                }
                else {
                    parse_and_execute(elseBranch);
                }
                break;
            }
            else {
                if(isThen) {
                    trueBranch = strdup(tempCommand);
                    isThen = 0;
                }
                if(isElse) {
                    elseBranch = strdup(tempCommand);
                    isElse = 0;
                }
            }
        }

        free(equation);
    } else {
        perror("Invalid conditional. Was not enclosed by '[' and ']'");
    }
}

void parse_and_execute(char *command) {
    char *ogcommand = strdup(command);
    char *args[MAX_ARGS];           
    char *args_pipe[MAX_ARGS];      
    char *token = strtok(command, " "); 
    int argc = 0, argc_pipe = 0;    
    int pipe_found = 0;


    while (token != NULL && argc < MAX_ARGS - 1) {
        if(strcmp(token, "if") == 0) {
            conditional_mode(ogcommand);
            return;
        }
        else if (strcmp(token, "|") == 0) {
            pipe_found = 1;         
            break;
        } 
        else if (strchr(token, '*')) {
            if (strchr(token, '>')) { // if there is output redirection and wildcard.
                if(strcmp(token, ">") != 0) {
                    token = strtok(token, ">");
                    expand_wildcards(token, args, &argc);
                    token = strtok(NULL, ">");
                }
                outputfd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0640);
                if(outputfd == -1) {
                    perror("Error opening output file.");
                    exit(EXIT_FAILURE);
                }
            }
            else if (strchr(token, '<')) { // if there is input redirection and wildcard.
                if(strcmp(token, "<") != 0) {
                    token = strtok(token, "<");
                    expand_wildcards(token, args, &argc);
                    token = strtok(NULL, "<");
                }
                inputfd = open(token, O_RDONLY);
                if(inputfd == -1) {
                    perror("Error opening input file.");
                    exit(EXIT_FAILURE);
                }
            }
            else {
                expand_wildcards(token, args, &argc);
            }
        }
        else if (strchr(token, '>')) {
            if(strcmp(token, ">") != 0) {
                token = strtok(token, ">");
                args[argc++] = token;
                token = strtok(NULL, ">");
            }
            else {
                token = strtok(NULL, " ");
            }
            outputfd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0640);
            if(outputfd == -1) {
                perror("Error opening output file.");
                exit(EXIT_FAILURE);
            }
        }
        else if (strchr(token, '<')) {
            if(strcmp(token, "<") != 0) {
                token = strtok(token, "<");
                args[argc++] = token;
                token = strtok(NULL, "<");
            }
            else {
                token = strtok(NULL, " ");
            }
            inputfd = open(token, O_RDONLY);
            if(inputfd == -1) {
                perror("Error opening input file.");
                exit(EXIT_FAILURE);
            }
        }
        else {
            args[argc++] = strdup(token);
        }
        token = strtok(NULL, " ");  
    }
    args[argc] = NULL;              

    if (pipe_found) {
        token = strtok(NULL, " ");
        while (token != NULL && argc_pipe < MAX_ARGS - 1) {
            args_pipe[argc_pipe++] = strdup(token); 
            token = strtok(NULL, " ");
        }
        args_pipe[argc_pipe] = NULL; 

        execute_pipe_command(args, args_pipe); 

        for (int i = 0; i < argc_pipe; i++) {
            free(args_pipe[i]);
        }
    } else {
        execute_command(args); 
    }

    for (int i = 0; i < argc; i++) {
        free(args[i]);
    }
}

void interactive_mode(void) {
    char command[MAX_COMMAND_LENGTH];

    printf("welcome to the shell! \n");
    while (1) {
        if(batchMode == 0) {
            printf("mysh> ");
        }
        if (!fgets(command, MAX_COMMAND_LENGTH, stdin)) {
            break;
        }

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("mysh: exiting\n");
            break;
        }

        parse_and_execute(command);
    }
}

void batch_mode(const char *filename) {
    batchMode = 1;
    //char command[MAX_COMMAND_LENGTH];
    batch_fd = open(filename, O_RDONLY);
    if(batch_fd == -1) {
        perror("Error opening batch file.");
        exit(EXIT_FAILURE);
    }
    dup2(batch_fd, STDIN_FILENO);
    close(batch_fd);
    interactive_mode();
    /*while (fgets(command, MAX_COMMAND_LENGTH, file)) {
        command[strcspn(command, "\n")] = 0;
        parse_and_execute(command);
    }*/

    //fclose(file);
}
