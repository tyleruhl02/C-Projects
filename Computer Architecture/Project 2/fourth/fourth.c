#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int num;
    char* name;
    int dist;
    struct node* next;
};

struct graph {
    int verticies;
    struct node** adjacencyLists;
};

struct node* createNode(int num, char* name, int dist) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->num = num;
  newNode->name = name;
  newNode->next = NULL;
  if(dist >= 0) {
    newNode->dist = dist;
  }
  else {
    newNode->dist = -1;
  }
  return newNode;
}

void createEdge(struct graph* g, struct node** a, struct node** b, int dist) {
    struct node* trailA = *a;
    struct node* tempA = *a;
    struct node* tempB = *b;

    struct node* newNodeA = createNode(tempB->num, tempB->name, dist);

    if(tempA->next) {
        if(strcmp(tempA->next->name, newNodeA->name) < 0) {
            newNodeA->next = tempA->next;
            tempA->next = newNodeA;
        }
        else {
            tempA = tempA->next;
            while(tempA->next) {
                if(strcmp(tempA->name, newNodeA->name) < 0) {
                    trailA->next = newNodeA;
                    newNodeA->next = tempA;
                    break;
                }
                tempA = tempA->next;
                trailA = trailA->next;
            }
            if(strcmp(tempA->name, newNodeA->name) < 0) {
                newNodeA->next = tempA;
                trailA->next = newNodeA;
            }
            else if(strcmp(tempA->name, newNodeA->name) > 0) {
                tempA->next = newNodeA;
            }
        }
    }
    else {
        tempA->next = newNodeA;
    }
    return;
}

void printAdjacencyList(struct node** adjacencyList) {
    struct node* pointer = *adjacencyList;
    if(pointer->next) {
        pointer = pointer->next;
        while(pointer) {
            printf("%s ", pointer->name);
            pointer = pointer->next;
        }
    }
    printf("\n");
    return;
}

void printGraph(struct graph* g) {
    for (int i = 0; i < g->verticies; i++) {
        struct node* temp = g->adjacencyLists[i];
        printf("\n Vertex %s (%d)\n: ", temp->name, temp->num);
        while (temp) {
            printf("%s : %d -> ", temp->name, temp->dist);
            temp = temp->next;
        }
        printf("\n");
    }
}

/*int popNode(struct node** head) {
    struct node* temp = *head;
    struct node* nextNode = temp->next;
    if(!nextNode) {
        free(temp);
        return 1;
    }
    else {
        while(nextNode->next) {
            temp = temp->next;
            nextNode = nextNode->next;
        }
        temp->next = NULL;
        free(nextNode);
        return 2;
    }
    return 0;
}*/

void freeAdjacencyList(struct node** head) {
    struct node* temp = *head;
    struct node* nextNode = temp->next;
    while(nextNode) {
        free(temp);
        temp = nextNode;
        nextNode = temp->next;
    }
    free(temp);
    return;
}

void freeGraph(struct graph* g) {
    for(int i = 0; i < g->verticies; i++) {
        struct node* temp = g->adjacencyLists[i];
        freeAdjacencyList(&temp);
    }
    free(g->adjacencyLists);
    return;
}


int countVerticies(struct node** adjacencyList) {
    struct node* temp = *adjacencyList;
    int i = 0; 
    while(temp->next) {
        i++;
        temp = temp->next;
    }
    return i;
}

int countInVerticies(struct graph* g, int num) {
    int count = 0;
    for(int i = 0; i < g->verticies; i++) {
        struct node* temp = g->adjacencyLists[i];
        while(temp->next) {
            temp = temp->next;
            if(temp->num == num) {
                count++;
                break;
            }
        }
    }
    return count;
}

struct stack {
    struct node* head;
};

void pushNode(struct stack* s, struct node** newNode) {
    struct node* temp = *newNode;
    struct node* addedNode = malloc(sizeof(struct node));
    addedNode->name = temp->name;
    addedNode->num = temp->num;
    addedNode->dist = temp->dist;
    addedNode->next = NULL;
    if(s->head) {
        struct node* pointer = s->head;
        while(pointer->next) {
            pointer = pointer->next;
        }
        pointer->next = addedNode;
    }
    else {
        s->head = addedNode;
    }
    return;
}

int popNode(struct stack* s) {
    struct node* pointer = s->head;
    struct node* trail = s->head;
    if(pointer->next) {
        pointer = pointer->next;
        while(pointer->next) {
            pointer = pointer->next;
            trail = trail->next;
        }
        trail->next = NULL;
        int returnValue = pointer->num;
        free(pointer);
        return returnValue;
    }
    else {
        int returnValue = pointer->num;
        s->head = NULL;
        free(pointer);
        return returnValue;
    }
}

bool isFull(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == -1) {
            return false;
        }
    }
    return true;
}

void printStack(struct stack* s) {
    struct node* pointer = s->head;
    printf("STACK: ");
    while(pointer) {
        printf("%s ->", pointer->name);
        pointer = pointer->next;
    }
    printf("\n");
}

/*void sortGraph(struct graph* g) {
    struct graph* graph = g;
    struct node* earliest;
    struct node* temp = malloc(sizeof(struct node));
    for(int i = 0; i < graph->verticies-1; i++) {
        earliest = graph->adjacencyLists[i];
        for(int j = i+1; j < graph->verticies; j++) {
            if(strcmp(earliest->name, graph->adjacencyLists[j]->name) > 0) {
                earliest = graph->adjacencyLists[j];
            }
        }
        if(earliest->num != graph->adjacencyLists[i]->num) {
            temp->dist = earliest->dist;
            temp->name = earliest->name;
            temp->next = earliest->next;

            earliest->dist = graph->adjacencyLists[i]->dist;
            earliest->name = graph->adjacencyLists[i]->name;
            earliest->next = graph->adjacencyLists[i]->next;

            graph->adjacencyLists[i]->dist = temp->dist;
            graph->adjacencyLists[i]->name = temp->name;
            graph->adjacencyLists[i]->next = temp->next;
        }
    }
    free(temp);
    for(int i = 0; i < g->verticies; i++) {
        g->adjacencyLists[i]->num = i;
    }
}*/

void DFS(struct graph* g) {
    struct node* start = g->adjacencyLists[0];
    int* visited = malloc(g->verticies * sizeof(int));
    struct stack* tempStack = malloc(sizeof(struct stack));
    tempStack->head = NULL;
    for(int i = 0; i < g->verticies; i++) {
        visited[i] = -1;
    }
    //int counter = 0;

    //printf("A\n");

    while(!isFull(visited, g->verticies)) {
        //printf("HEY-O\n");
        for(int i = 0; i < g->verticies; i++) {
            if(visited[i] == -1) {
                start = g->adjacencyLists[i];
                pushNode(tempStack, &start);
                break;
            }
        }
        while(tempStack->head) {
            start = g->adjacencyLists[popNode(tempStack)];
            bool seen = false;
            for(int i = 0; i < g->verticies; i++) {
                if(visited[i] == start->num) {
                    seen = true;
                    break;
                }
            }
            if(!seen) {
            printf("%s ", start->name);
            visited[start->num] = start->num;
            start = start->next;
            if(start) {
                do {
                    seen = false;
                    for(int i = 0; i < g->verticies; i++) {
                        if(visited[i] == start->num) {
                            seen = true;
                            break;
                        }
                    }
                    if(!seen) {
                        pushNode(tempStack, &start);
                    }
                    start = start->next;
                } while(start);
            }
            }
        }
    }
    free(tempStack);
    free(visited);
    printf("\n");
    return;
}

void swapInput(char** input, int a, int b) {
    char* temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}

void sortInput(char** input, int size) {
    int min;
    for(int i = 0; i < size; i++) {
        min = i;
        for(int j = i+1; j < size; j++) {
            if(strcmp(input[min], input[j]) > 0) {
                min = j;
            }
        }
        if(min != i) {
            swapInput(input, i, min);
        }
    }
}

int main(int argc, char* argv[]) {
    FILE * fp1;
    //FILE * fp2;

    int num, num2;
    int num1 = -1;

    fp1 = fopen(argv[1], "r+");
    //fp2 = fopen(argv[2], "r+");
    fscanf(fp1, "%d", &num);

    struct graph* g = malloc(sizeof(struct graph));
    g->verticies = num;
    g->adjacencyLists = malloc(num * sizeof(struct node*));

    char** input = malloc(num * sizeof(char *));

    for(int i = 0; i < num; i++) {
        input[i] = malloc(10 * sizeof(char));
        fscanf(fp1, "%s", input[i]);
    }

    sortInput(input, num);

    for(int i = 0; i < num; i++) {
        g->adjacencyLists[i] = createNode(i, input[i], -1);
    }

    //sortGraph(g);

    //printGraph(g);
    //return EXIT_SUCCESS;

    char str1[10];
    char str2[10];
    int node1, node2;

    while(!feof(fp1)) {
        num2 = fscanf(fp1, "%s", str1);
        if(num2 == -1) {
            break;
        }
        fscanf(fp1, "%s", str2);
        fscanf(fp1, "%d", &num1);
        int j = 0;
        bool valid = true;
        for(int i = 0; i < num; i++) {
            while(str1[j]) {
                if(input[i][j] != str1[j]) {
                    valid = false;
                    break;
                }
                j++;
            }
            if(valid) {
                node1 = i;
            }
            valid = true;
            j = 0;
        }
        j = 0;
        valid = true;
        for(int i = 0; i < num; i++) {
            while(str2[j]) {
                if(input[i][j] != str2[j]) {
                    valid = false;
                    break;
                }
                j++;
            }
            if(valid) {
                node2 = i;
            }
            valid = true;
            j = 0;
        }
        createEdge(g, &g->adjacencyLists[node1], &g->adjacencyLists[node2], num1);
    }

    DFS(g);

    //printGraph(g);

    freeGraph(g);

    for(int i = 0; i < num; i++) {
        free(input[i]);
    }
    free(input);
    free(g);

    return EXIT_SUCCESS;
}