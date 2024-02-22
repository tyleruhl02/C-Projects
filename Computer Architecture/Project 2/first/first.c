#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int num;
    char* name;
    struct node* next;
};

struct graph {
    int verticies;
    struct node** adjacencyLists;
};

struct node* createNode(int num, char* name) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->num = num;
  newNode->name = name;
  newNode->next = NULL;
  return newNode;
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
        printf("%d: ", i);
        printAdjacencyList(&temp);
    }
}

void createEdge(struct graph* g, struct node** a, struct node** b) {
    struct node* trailA = *a;
    struct node* trailB = *b;
    struct node* tempA = *a;
    struct node* tempB = *b;

    struct node* newNodeA = createNode(tempB->num, tempB->name);
    struct node* newNodeB = createNode(tempA->num, tempA->name);
    
    if(tempA->next) {
        if(strcmp(tempA->next->name, newNodeA->name) > 0) {
            newNodeA->next = tempA->next;
            tempA->next = newNodeA;
        }
        else {
            tempA = tempA->next;
            while(tempA->next) {
                if(strcmp(tempA->name, newNodeA->name) > 0) {
                    trailA->next = newNodeA;
                    newNodeA->next = tempA;
                    break;
                }
                tempA = tempA->next;
                trailA = trailA->next;
            }
            if(strcmp(tempA->name, newNodeA->name) > 0) {
                newNodeA->next = tempA;
                trailA->next = newNodeA;
            }
            else if(strcmp(tempA->name, newNodeA->name) < 0) {
                tempA->next = newNodeA;
            }
        }
    }
    else {
        tempA->next = newNodeA;
    }
    if(tempB->next) {
        if(strcmp(tempB->next->name, newNodeB->name) > 0) {
            newNodeB->next = tempB->next;
            tempB->next = newNodeB;
        }
        else {
            tempB = tempB->next;
            while(tempB->next) {
                if(strcmp(tempB->name, newNodeB->name) > 0) {
                    trailB->next = newNodeB;
                    newNodeB->next = tempB;
                    break;
                }
                tempB = tempB->next;
                trailB = trailB->next;
            }
            if(strcmp(tempB->name, newNodeB->name) > 0) {
                newNodeB->next = tempB;
                trailB->next = newNodeB;
            }
            else if(strcmp(tempB->name, newNodeB->name) < 0) {
                tempB->next = newNodeB;
            }
        }
    }
    else {
        tempB->next = newNodeB;
    }
    return;
}

/*void createEdge(struct graph* g, struct node** a, struct node** b) {
    //struct node* aPtr = *a;
    //struct node* bPtr = *b;
    struct node* tempA = *a;
    struct node* tempB = *b;
    struct node* newNodeA = createNode(tempB->num, tempB->name);
    struct node* newNodeB = createNode(tempA->num, tempA->name);

    bool valid = false;
    if(tempA->num == 0 || tempB->num == 0) {
        valid = true;
        //printGraph(g);
        printf("A: %s, B: %s\n", tempA->name, tempB->name);
    }

    if(!tempA->next) {
        tempA->next = newNodeA;
    }
    else {
        if(strcmp(tempA->next->name, newNodeA->name) > 0) {
            newNodeA->next = tempA->next;
            tempA->next = newNodeA;
        }
        else if(tempA->next->next) {
            while(tempA->next->next) {
                tempA = tempA->next;
                if(strcmp(tempA->next->name, newNodeA->name) > 0) {
                    newNodeA->next = tempA->next;
                    tempA->next = newNodeA;
                    break;
                }
            }
        }
        else {
            tempA = tempA->next;
            tempA->next = newNodeA;
        }
    }
    if(!tempB->next) {
        tempB->next = newNodeB;
    }
    else {
        if(strcmp(tempB->next->name, newNodeB->name) > 0) {
            newNodeB->next = tempB->next;
            tempB->next = newNodeB;
        }
        else if(tempB->next->next) {
            while(tempB->next->next) {
                tempB = tempB->next;
                if(strcmp(tempB->next->name, newNodeB->name) > 0) {
                    newNodeB->next = tempB->next;
                    tempB->next = newNodeB;
                    break;
                }
            }
        }
        else {
            tempB = tempB->next;
            tempB->next = newNodeB;
        }
    }
    else if(tempA->next) {
        do {
            tempA = tempA->next;
            if(strcmp(tempA->name, newNodeA->name) > 0) {
                if(valid) {
                    printf("1\n");
                }
                break;
            }
        } while(tempA->next);
    }
    else {

    }
    if(valid) 
        printf("newNodeA: %s\ttempA: %s\n", newNodeA->name, tempA->name);
    newNodeA->next = tempA->next;
    tempA->next = newNodeA;
    if(valid) {
        while(aPtr) {
            printf("%s -> ", aPtr->name);
            aPtr = aPtr->next;
        }
        printf("\n\n\n");
    }
    while(tempB->next) {
        tempB = tempB->next;
        if(strcmp(tempB->name, newNodeB->name) > 0) {
            if(valid) {
                printf("2\n");
                printf("%s, %s\n", tempA->name, newNodeA->name);
            }
            break;
        }
    }
    if(valid) 
        printf("newNodeB: %s\ttempB: %s\n", newNodeB->name, tempB->name);
    newNodeB->next = tempB->next;
    tempB->next = newNodeB;
    if(valid) {
        while(bPtr) {
            printf("%s -> ", bPtr->name);
            bPtr = bPtr->next;
        }
        printf("\n\n\n");
    }
    if(valid) {
        //printGraph(g);
        //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    return;
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

/*void alphabeticalAdjacencyList(struct node** adjacencyList) {
    struct node* pointer = *adjacencyList;
    struct node* base = *adjacencyList;
    int degree = countVerticies(&pointer);
    int earliest = 0;
    int counter = 0;
    int* usedIndecies = malloc(degree * sizeof(int));
    for(int i = 0; i < degree; i++) {
        usedIndecies[i] = -1;
    }
    if(!pointer->next) {
        free(usedIndecies);
        printf("\n");
        return;
    }
    base = pointer->next;

    for(int i = 0; i < degree; i++) {
        pointer = *adjacencyList;
        pointer = pointer->next;
        counter = 0;
        bool valid = true;
        while(pointer->next) {
            pointer = pointer->next;
            counter++;
            if(strcmp(base->name, pointer->name) > 0) {
                valid = true;
                for(int j = 0; j < degree; j++) {
                    if(usedIndecies[j] == counter) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    earliest = counter;
                    base = pointer;
                }
            }
        }
        usedIndecies[i] = earliest;
        earliest = 0;
        base = *adjacencyList;
        base = base->next;
        for(int j = 0; j < degree; j++) {
            valid = true;
            for(int k = 0; k < degree; k++) {
                if(usedIndecies[k] == j) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                earliest = j;
                break;
            }
            base = base->next;
        }
    }
    
    for(int i = 0; i < degree; i++) {
        pointer = *adjacencyList;
        pointer = pointer->next;
        for(int j = 0; j < usedIndecies[i]; j++) {
            pointer = pointer->next;
        }
        printf("%s ", pointer->name);
    }
    printf("\n");
    free(usedIndecies);
    return;
}*/

int main(int argc, char* argv[]) {
    FILE * fp1;
    FILE * fp2;

    int num, num2;

    fp1 = fopen(argv[1], "r+");
    fp2 = fopen(argv[2], "r+");
    fscanf(fp1, "%d", &num);

    struct graph* g = malloc(sizeof(struct graph));
    g->verticies = num;
    g->adjacencyLists = malloc(num * sizeof(struct node*));

    char** input = malloc(num * sizeof(char *));

    for(int i = 0; i < num; i++) {
        input[i] = malloc(10 * sizeof(char));
        fscanf(fp1, "%s", input[i]);
        g->adjacencyLists[i] = createNode(i, input[i]);
    }

    char str1[10];
    char str2[10];
    int node1, node2;

    while(!feof(fp1)) {
        num2 = fscanf(fp1, "%s", str1);
        if(num2 == -1) {
            break;
        }
        fscanf(fp1, "%s", str2);
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
        createEdge(g, &g->adjacencyLists[node1], &g->adjacencyLists[node2]);
    }

    while(!feof(fp2)) {
        num2 = fscanf(fp2, "%s", str1);
        if(num2 == -1) {
            break;
        }
        fscanf(fp2, "%s", str2);
        int j = 0;
        bool valid = true;
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
        if(str1[0] == 'd') {
            printf("%d\n", countVerticies(&g->adjacencyLists[node2]));
        }
        else if(str1[0] == 'a') {
            //alphabeticalAdjacencyList(&g->adjacencyLists[node2]);
            printAdjacencyList(&g->adjacencyLists[node2]);
        }
    }

    freeGraph(g);

    for(int i = 0; i < num; i++) {
        free(input[i]);
    }
    free(input);
    free(g);

    return EXIT_SUCCESS;
}