#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

void enqueueNode(struct node** head, int num) {
    struct node* currentNode = *head;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    if(currentNode->data == -31410583) {
        currentNode->data = num;
        free(newNode);
    }
    else {
        newNode->data = num;
        newNode->next = NULL;
        currentNode->next = newNode;
    }
    return;
}

void pushNode(struct node** head, int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    struct node* temp = *head;
    newNode->data = num;
    if(temp->data == -31410583) {
        newNode->next = NULL;
        free(temp);
    }
    else {
        newNode->next = temp;
    }
    *head = newNode;
    return;
}

void popNode(struct node** head) {
    struct node* temp = *head;
    if(temp == NULL) {
        return;
    }
    if(temp->next == NULL) {
        temp->data = -31410583;
    }
    else {
        *head = temp->next;
        free(temp);
    }
    return;
}

void printList(struct node* head) {
    if(head->data == -31410583) {
        printf("EMPTY\n");
        return;
    }
    while(head != NULL) {
        if(head->data != -31410583) {
            printf("%d ", head->data);
        }
        head = head->next;
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[]) {
    FILE * fp;
    char str[10];
    int num;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->data = -31410583;
    head->next = NULL;
    if((fp = fopen(argv[1], "r+")) == NULL)
    {
        printf("error\n");
        return EXIT_FAILURE;
    }  

    int num2;
    //num2 = 7;

    while(!feof(fp)) {
        num2 = fscanf(fp, "%s", str);
        if(num2 == -1) {
            break;
        }
        if(str[1] != 'O') {
            fscanf(fp, "%d", &num);
            if(str[0] == 'P') { // PUSH
                pushNode(&head, num);
            }
            else if(str[0] == 'E') { // ENQUEUE
                enqueueNode(&head, num);
            }
        }
        else { // POP
            popNode(&head);
        }
        printList(head);
        //printf("num2: %d\n", num2);
        //printf("%s\n", str);

    } //while(fgetc(fp) != EOF);

    while(head->data != -31410583) {
        popNode(&head);
    }

    free(head);

    return EXIT_SUCCESS;
}