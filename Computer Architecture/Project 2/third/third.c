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

/*void createEdge(struct graph* g, struct node** a, struct node** b) {
    struct node* tempA = *a;
    struct node* tempB = *b;
    struct node* newNodeA = createNode(tempB->num, tempB->name);
    struct node* newNodeB = createNode(tempA->num, tempA->name);

    while(strcmp(tempA->name, newNodeA->name) > 0) {
        tempA = tempA->next;
    }
    while(strcmp(tempB->name, newNodeB->name) > 0) {
        tempB = tempB->next;
    }
    //struct node* tempC = tempA->next;
    //struct node* tempD = tempB->next;
    newNodeA->next = tempA->next;
    newNodeB->next = tempB->next;
    tempA->next = newNodeA;
    tempB->next = newNodeB;

    return;
}*/

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
        printf("%s: ", temp->name);
        printAdjacencyList(&temp);
    }
}

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

struct queue {
    struct node* head;
};

void enqueue(struct queue *q, struct node** newNode) {
    struct node* temp = *newNode;
    struct node* addedNode = malloc(sizeof(struct node));
    addedNode->name = temp->name;
    addedNode->num = temp->num;
    addedNode->next = NULL;
    if(q->head) {
        struct node* pointer = q->head;
        while(pointer->next) {
            pointer = pointer->next;
        }
        pointer->next = addedNode;
    }
    else {
        q->head = addedNode;
    }
    return;
}

int dequeue(struct queue *q) {
    struct node* temp = q->head;
    int returnValue = temp->num;
    q->head = temp->next;
    free(temp);
    return returnValue;
}

void printQueue(struct queue *q) {
    struct node* temp = q->head;
    printf("QUEUE: ");
    while(temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void BFS(struct graph* g, int index) {
    struct node* start = g->adjacencyLists[index];
    int* visited = malloc(g->verticies * sizeof(int));
    struct queue* tempQueue = malloc(sizeof(struct queue));
    tempQueue->head = NULL;
    for(int i = 0; i < g->verticies; i++) {
        visited[i] = -1;
    }
    int counter = 0;

    enqueue(tempQueue, &start);
    visited[counter++] = index;
    printf("%s ", start->name);

    while(tempQueue->head) {
        //printQueue(tempQueue);
        start = g->adjacencyLists[dequeue(tempQueue)];
        start = start->next;
        if(start) {
            do {
                bool seen = false;
                for(int i = 0; i < counter+1; i++) {
                    if(visited[i] == start->num) {
                        seen = true;
                        break;
                    }
                }
                if(!seen) {
                    enqueue(tempQueue, &start);
                    visited[counter++] = start->num;
                    printf("%s ", start->name);
                }
                start = start->next;
            } while(start);
        }
        //break;
        //&g->adjacencyLists[node2]
    }
    printf("\n");
    free(visited);
    free(tempQueue);
    //free(queue);
}

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
        //fscanf(fp2, "%s", str2);
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
                node2 = i;
            }
            valid = true;
            j = 0;
        }
        //printf("%s:%d", str1, node2);
        BFS(g, node2);
        /*if(str1[0] == 'd') {
            printf("%d\n", countVerticies(&g->adjacencyLists[node2]));
        }*/
        //if(str1[0] == 'a') {
            //alphabeticalAdjacencyList(&g->adjacencyLists[node2]);
        //}
    }

    //printGraph(g);

    freeGraph(g);

    for(int i = 0; i < num; i++) {
        free(input[i]);
    }
    free(input);
    free(g);

    return EXIT_SUCCESS;
}