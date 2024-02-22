#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertNode(struct node** head, int num) {
    struct node* currentNode = *head;
    struct node* newNode = malloc(sizeof(struct node));
    while(currentNode->next != NULL) {
        if(currentNode->next->data == num) {
            free(newNode);
            return;
        }
        else if(currentNode->next->data > num) {
            newNode->data = num;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        currentNode = currentNode->next;
    }
    newNode->data = num;
    newNode->next = NULL;
    currentNode->next = newNode;
    return;
}

void printList(struct node* head) {
    head = head->next;
    if(head == NULL) {
        printf("EMPTY");
    }
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int deleteNode(struct node** head, int data) {
    struct node* prev = *head;
    struct node* current = *head;
    
    if(current-> data == data) {
        *head = current->next;
        free(current);
        return 1;
    }

    current = current->next;

    while(current != NULL) {
        if(current->data == data) {
            prev->next = current->next;
            free(current);
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    FILE * fp;
    char str[10];
    int num;
    struct node* head = malloc(sizeof(struct node));
    head->data = -31410583;
    head->next = NULL;

    if((fp = fopen(argv[1], "r+")) == NULL)
    {
        printf("error\n");
        return EXIT_FAILURE;
    }  

    int num2 = 0;
    char str2[10];
    int valid = 0;

    do {
        fscanf(fp, "%s", str);
        fscanf(fp, "%d", &num);

        for(int i = 0; i < 10; i++) {
            if(str[i] != str2[i]) {
                valid = 1;
                break;
            }
        }
        if(num != num2) {
            valid = 1;
        }
        if(!valid) {
            continue;
        }

        if(str[0] == 'I') {
            insertNode(&head, num);
        }
        else if(str[0] == 'D') {
            deleteNode(&head, num);
        }
        printList(head);
        for(int i = 0; i < 10; i++) {
            str2[i] = str[i];
        }
        num2 = num;
        valid = 0;

    } while(fgetc(fp) != EOF);

    while(head->next != NULL) {
        deleteNode(&head, head->next->data);
    }

    free(head);

    return EXIT_SUCCESS;
}

/*struct Node {
    int data;
    struct Node* next;
}

void add_node(strut Node** head, struct Node node) {
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    *new = node;
    new->next = *head;
    *head = new;
    return;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int remove_node(struct Node** head, int data) {
    struct Node* prev = *head;
    struct Node* current = *head;
    
    if(current-> data == data) {
        *head = current->next;
        free(current);
        return 1;
    }

    current = current->next;

    while(current != NULL) {
        if(current->data == data) {
            prev->next = current->next;
            free(current);
            return true;
        }

        prev = current;
        current = current->next;
    }
}

int main(int argc, char** argv) {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 8;
    head->next = NULL;
    for(int i = 0; i < 5; i++) {
        struct Node node;
        node.data = i;
        add_node(&head, node);
    }

    printList(head);
    for(int i = 0; i < 5; i++) {
        remove_node(&head, i);
    }
    remove_node(&head, 800);

    return EXIT_SUCCESS;
}*/