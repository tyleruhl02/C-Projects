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
    return;
}

void printGraph(struct graph* g) {
    for (int i = 0; i < g->verticies; i++) {
        struct node* temp = g->adjacencyLists[i];
        printf("\n Vertex %d\n: ", i);
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
}

void freeAdjacencyList(struct node** head) {
    struct node* temp = *head;
    int num = 2;
    while(num == 2) {
        num = popNode(&temp);
    }
    return;
}

void freeGraph(struct graph* g) {
    for(int i = 0; i < g->verticies; i++) {
        struct node* temp = g->adjacencyLists[i];
        freeAdjacencyList(&temp);
    }
    free(g->adjacencyLists);
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

int main(int argc, char* argv[]) {
    FILE * fp1;
    FILE * fp2;

    int num, num2;
    int num1 = -1;

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
        g->adjacencyLists[i] = createNode(i, input[i], -1);
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

    /*while(!feof(fp2)) {
        num2 = fscanf(fp2, "%s", str1);
        if(num2 == -1) {
            break;
        }
        fscanf(fp2, "%s", str2);
        printf("%s %s\n", str1, str2);
    }*/

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
        if(str1[0] == 'o') {
            printf("%d\n", countVerticies(&g->adjacencyLists[node2]));
        }
        if(str1[0] == 'i') {
            printf("%d\n", countInVerticies(g, node2));
        }
        else if(str1[0] == 'a') {
            printAdjacencyList(&g->adjacencyLists[node2]);
        }
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