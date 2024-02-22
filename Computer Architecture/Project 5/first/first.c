#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

struct node {
    char* name;
    int index;
    int numInputs;
    int* inputs;
    bool* oppositeInputs;
    int operation;
    struct node* next;
};

struct node* createNode(char* name, int index, int numInputs, int* inputs, int operation, struct node* next) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->name = name;
    newNode->index = index;
    newNode->numInputs = numInputs;
    newNode->inputs = inputs;
    newNode->operation = operation;
    newNode->next = next;
    newNode->oppositeInputs = malloc(numInputs * sizeof(bool));
    for(int i = 0; i < numInputs; i++) {
        newNode->oppositeInputs[i] = false;
    }
    return newNode;
}

void printNode(struct node* node) {
    printf("NAME: %s\n", node->name);
    printf("INDEX: %d\n", node->index);
    printf("INPUTS: ");
    for(int i = 0; i < node->numInputs; i++) {
        printf("%d, ", node->inputs[i]);
    }
    printf("\nOPPOINPUTS: ");
    for(int i = 0; i < node->numInputs; i++) {
        printf("%d, ", node->oppositeInputs[i]);
    }
    printf("\nOPERATION: %d\n", node->operation);
    if(node->next) {
        printf("NEXT: %s\n\n", node->next->name);
    }
    else {
        printf("NEXT: NULL\n\n");
    }
}

void printGNodes(struct node** head, int* gIndexes, int size) {
    struct node* temp = *head;
    while(temp) {
        for(int i = 0; i < size; i++) {
            if(temp->index == gIndexes[i]) {
                printNode(temp);
            }
        }
        temp = temp->next;
    }
}

int getIndex(char** list, int size, char* word) {
    for(int i = 0; i < size; i++) {
        if(strcmp(word, list[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int getIndex2(struct node** head, char* word) {
    struct node* temp = *head;
    while(temp) {
        if(strcmp(word, temp->name) == 0) {
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

int logBase2(float f) {
    int i = 0; 
    while(f > 1) {
        f/=2;
        i++;
    }
    return i;
}

bool* toBinary(int num, int max, int dim) {
    bool* returnValue = malloc(dim * sizeof(bool));
    int i = 0;
    while(i < dim) {
        if(num - max >= 0) {
            returnValue[i] = true;
            num = num - max;
        }
        else {
            returnValue[i] = false;
        }
        max /= 2;
        i++;
    }
    //printf("%d %d\n", returnValue[0], returnValue[1]);
    return returnValue;
}

void createInputSequence(bool** input, int dim1, int dim2) {
    for(int i = 0; i < dim2; i++) {
        bool* binary = toBinary(i, dim2/2, dim1);
        for(int j = 0; j < dim1; j++) {
            input[j][i] = binary[j];
        }
        free(binary);
    }
}

void mirrorInput(bool** input, int dim1, int dim2) {
    for(int i = 0; i < dim2; i++) {
        for(int j = 0; j < dim1; j++) {
            input[j][dim2*2-i-1] = input[j][i];
        }
    }
}

void addNewInput(bool** input, int dim1, int dim2) {
    for(int i = 0; i < dim2; i++) {
        input[dim1][i] = i >= dim2/2;
    }
}

void createGreyCodeInputs(bool** input, int dim1, int dim2) {
    input[0][0] = false;
    input[0][1] = true;
    int tempdim1 = 1;
    int tempdim2 = 2;
    for(int i = 1; i < dim1; i++) {
        mirrorInput(input, tempdim1, tempdim2);
        tempdim2*=2;
        addNewInput(input, tempdim1, tempdim2);
        tempdim1++;
    }
}

bool isValid(int operation, int numOfInputs) {
    if(operation == 3 && numOfInputs != 1) {
        return false;
    }
    if((operation == 0 || operation == 1 || operation == 2) && numOfInputs != 2) {
        return false;
    }
    return true;
}

bool updateGs(struct node** head, int* indexes, int size) {
    bool carry = false;
    for(int i = size-1; i >= 0; i--) {
        struct node* temp = *head;
        //int counter = 0;
        carry = false;
        while(temp) {
            if(indexes[i] == temp->index) {
                // bool valid = isValid(temp->operation, temp->numInputs);
                // while(!valid) {
                //     temp->operation = temp->operation + 1;
                //     valid = isValid(temp->operation, temp->numInputs);
                // }
                // if(temp->operation > 5) {
                //     carry = true;
                //     temp->operation = 0;
                // }
                // //printf("GINDEX: %s\n", temp->name);
                // break;

                temp->operation = temp->operation + 1;
                if(temp->operation > 5) {
                    carry = true;
                    temp->operation = 0;
                    if(i == 0) {
                        return false;
                    }
                }
            }
            temp = temp->next;
        }
        if(!carry) {
            break;
        }
    }
    return true;
}

bool computeOperation(bool* inputs, int numOfInputs, int operation, bool* oppoInputs) {
    if(operation == 3 && numOfInputs != 1) {
        return false;
    }
    if((operation == 0 || operation == 1 || operation == 2) && numOfInputs != 2) {
        return false;
    }
    if(operation == 3) { // NOT
        return !inputs[0];
    }
    else if(operation == 0) { // OR
        return inputs[0] || inputs[1];
    }
    else if(operation == 1) { // AND
        return inputs[0] && inputs[1];
    }
    else if(operation == 2) { // XOR
        return (inputs[0] == false && inputs[1] == true) || (inputs[0] == true && inputs[1] == false);
    }
    else if(operation == 4) { // DECODER
        bool returnVal = (inputs[0] == false && oppoInputs[0] == true) || (inputs[0] == true && oppoInputs[0] == false);
        for(int i = 1; i < numOfInputs; i++) {
            bool otherValue = (inputs[i] == false && oppoInputs[i] == true) || (inputs[i] == true && oppoInputs[i] == false);
            returnVal = returnVal && otherValue;
        }
        return returnVal;
    }
    else if(operation == 5) {
        int numOfSelectors = 1;
        while((numOfSelectors + (1 << numOfSelectors)) != numOfInputs) {
            numOfSelectors++;
            if(numOfSelectors == 8) {
                return false;
            }
        }

        int counter = 1;
        int returnIndex = 0;
        for(int i = (1 << numOfSelectors) + numOfSelectors -1; i >= (1 << numOfSelectors); i--) {
            //printf("%d\n", inputs[i]*counter);
            returnIndex += inputs[i]*counter;
            counter*=2;
        }

        //for(int i = )

        //printf("TICKER: %d\tRETURNINDEX: %d\tINPUTS: %d %d %d %d %d %d\n", ticker, returnIndex, inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5]);
        //printf("%d", ticker);


        //printf("returnIndex: %d\n", returnIndex);

        /*bool returnVal = false;

        for(int i = 0; i < (1 << numOfSelectors); i++) {
            bool* binary = toBinary(i, (1 << (numOfSelectors-1)), numOfSelectors);
            // printf("i: %d\t", i);
            // for(int j = 0; j < numOfSelectors; j++) {
            //     printf("%d ", binary[j]);
            // }
            // printf("\n");
            bool tempVal = inputs[i];
            //printf("INPUT[%d]: %d\n", i, inputs[i]);
            for(int j = 0; j < numOfSelectors; j++) {
                //printf("j: %d\n", ((inputs[(1 << numOfSelectors) + j] == false && binary[j] == true) || (inputs[(1 << numOfSelectors) + j] == true && binary[j] == false)));
                tempVal = tempVal && ((inputs[(1 << numOfSelectors) + j] == false && binary[j] == true) || (inputs[(1 << numOfSelectors) + j] == true && binary[j] == false));
            }
            //printf("\n");
            returnVal = returnVal || tempVal;
            free(binary);
        }
        printf("%d ", returnVal);*/
        //printf("%d ", inputs[returnIndex]);
        return inputs[returnIndex];
    }
    return false;
}

bool runCircuit(bool** inputs, int numOfInputs, struct node** head, bool** outputs, int index, bool* tempValues, int tempValuesSize, int* outputIndexes, int numOfOutputs) {
    for(int i = 0; i < numOfInputs; i++) { // PUT THE INPUT VALUES INTO THE ARRAY
        tempValues[i] = inputs[i][index];
        //printf("%d ", tempValues[i]);
    }
    //printf("\n");
    for(int i = tempValuesSize - numOfInputs - 1; i >= 0; i--) { // FOR EVERY VALUE NEEDED NOT INCLUDING THE INPUTS
        struct node* tempNode = *head;
        for(int j = 0; j < i; j++) {    // GO TO THE FIRST NODE NOT DEALT WITH
            tempNode = tempNode->next;
        }
        //printf("NODE NAME: %s\t\t", tempNode->name);

        bool* tempInputs = malloc((tempNode->numInputs) * sizeof(bool));    // FIND THE INPUTS FOR THE NODE IN TERMS OF 0's and 1's
        bool* tempOppoInputs = malloc((tempNode->numInputs) * sizeof(bool));
        for(int j = 0; j < (tempNode->numInputs); j++) {
            if(tempNode->inputs[j] < 0) {
                tempInputs[j] = (tempNode->inputs[j])+2;
            }
            else {
                tempInputs[j] = tempValues[tempNode->inputs[j]];
                //printf("%d ", tempInputs[j]);
            }
            tempOppoInputs[j] = tempNode->oppositeInputs[j];
        }
        //printf("\t\t");

        tempValues[tempNode->index] = computeOperation(tempInputs, tempNode->numInputs, tempNode->operation, tempOppoInputs);   
        
        //printf("OUTPUT: %d\n", tempValues[tempNode->index]);
        
        free(tempInputs);
        free(tempOppoInputs);
    }

    

    bool validSoFar = true;
    for(int i = 0; i < numOfOutputs; i++) { // potentially an error if outputs aren't sequential (OUT1 OUT3 OUT2)
        //printf("OUTPUT INDEX: %d\toutputIndexes[i]: %d\t", i, outputIndexes[i]);
        if(outputs[i][index] != tempValues[outputIndexes[i]]) {
            //printf("INDEX: %d\tOUTPUT: %d\t\tEXPECTED OUTPUT: %d", i, tempValues[outputIndexes[i]], outputs[i][index]);
            validSoFar = false;
            break;
        }
    }
   // printf("\n");
    return validSoFar;

    //printf("OUTPUT: %d\n", tempValues[7]);

    //free(neededInputs);
    //return false;
}

int main(int argc, char* argv[]) {
    FILE * fp1;
    fp1 = fopen(argv[1], "r+");

    // int num;
    int num1;
    int num2;
    char * word = malloc(15 * sizeof(char));
    char ** inputNames;
    char ** outputNames;
    bool ** inputValues;
    bool ** outputValues;

    fscanf(fp1, "%s", word);
    if(strcmp(word, "INPUTVAR") == 0) {
        fscanf(fp1, "%d", &num1);
        inputNames = malloc(num1 * sizeof(char *));
        inputValues = malloc(num1 * sizeof(bool *));
        for(int i = 0; i < num1; i++) {
            inputNames[i] = malloc(10 * sizeof(char));
            fscanf(fp1, "%s", inputNames[i]);
            inputValues[i] = malloc((1 << num1) * sizeof(bool));
        }

        fscanf(fp1, "%s", word);
        fscanf(fp1, "%d", &num2);
        outputNames = malloc(num2 * sizeof(char *));
        outputValues = malloc(num2 * sizeof(bool *));
        for(int i = 0; i < num2; i++) {
            outputNames[i] = malloc(10 * sizeof(char));
            fscanf(fp1, "%s", outputNames[i]);
            outputValues[i] = malloc((1 << num1) * sizeof(bool));
        }
    }
    else {
        fscanf(fp1, "%d", &num2);
        outputNames = malloc(num2 * sizeof(char *));
        outputValues = malloc(num2 * sizeof(bool *));
        for(int i = 0; i < num2; i++) {
            outputNames[i] = malloc(10 * sizeof(char));
            fscanf(fp1, "%s", outputNames[i]);
        }

        fscanf(fp1, "%s", word);
        fscanf(fp1, "%d", &num1);
        inputNames = malloc(num1 * sizeof(char *));
        inputValues = malloc(num1 * sizeof(bool *));
        for(int i = 0; i < num1; i++) {
            inputNames[i] = malloc(10 * sizeof(char));
            fscanf(fp1, "%s", inputNames[i]);
            inputValues[i] = malloc((1 << num1) * sizeof(bool));
        }
        for(int i = 0; i < num2; i++) {
            outputValues[i] = malloc((1 << num1) * sizeof(bool));
        }
    }

    
    fscanf(fp1, "%s", word);
    
    createInputSequence(inputValues, num1, (1 << num1));

    // for(int i = 0; i < (1 << num1); i++) {
    //     for(int j = 0; j < num1; j++) {
    //         printf("%d ", inputValues[j][i]);
    //     }
    //     printf("\n%d: ", i+1);
    // }

    //createGreyCodeInputs(inputValues, num1, (1 << num1));

    for(int i = 0; i < num2; i++) {
        fscanf(fp1, "%s", word);
        int j = getIndex(outputNames, num2, word);
        for(int k = 0; k < (1 << num1); k++) {
            int temp;
            fscanf(fp1, "%d", &temp);
            outputValues[j][k] = temp == 1;
        }
    }
    
    //char a = ' ';
    struct node* tempNode = NULL;
    int counter = num1;
    int gcounter = 0;

    int* gIndexes = malloc(100 * sizeof(int));
    int* outputIndexes = malloc(num2 * sizeof(int));

    int validity = 1;

    while(!feof(fp1)) {
        validity = fscanf(fp1, "%s", word);
        if(validity == -1) {
            break;
        }
        //printf("%s\n", word);
        if(strcmp(word, "OR") == 0) {
            char* word1 = malloc(15 * sizeof(char));      
            char* word2 = malloc(15 * sizeof(char));
            char* word3 = malloc(15 * sizeof(char));

            fscanf(fp1, "%s", word1);
            fscanf(fp1, "%s", word2);
            fscanf(fp1, "%s", word3);

            if(word3[0] == 'O' && word3[1] == 'U' && word3[2] == 'T') {
                outputIndexes[getIndex(outputNames, num2, word3)] = counter;
            }

            int index1 = getIndex(inputNames, num1, word1);
            if(index1 == -1) {
                index1 = getIndex2(&tempNode, word1);
            }
            int index2 = getIndex(inputNames, num1, word2);
            if(index2 == -1) {
                index2 = getIndex2(&tempNode, word2);
            }

            int* inputs = malloc(2 * sizeof(int));
            inputs[0] = index1;
            inputs[1] = index2;

            tempNode = createNode(word3, counter, 2, inputs, 0, tempNode);

            free(word1);
            free(word2);

            //printNode(tempNode);
            counter++;
        }
        else if(strcmp(word, "AND") == 0) {
            char* word1 = malloc(15 * sizeof(char));      
            char* word2 = malloc(15 * sizeof(char));
            char* word3 = malloc(15 * sizeof(char));

            fscanf(fp1, "%s", word1);
            fscanf(fp1, "%s", word2);
            fscanf(fp1, "%s", word3);

            if(word3[0] == 'O' && word3[1] == 'U' && word3[2] == 'T') {
                outputIndexes[getIndex(outputNames, num2, word3)] = counter;
            }

            int index1 = getIndex(inputNames, num1, word1);
            if(index1 == -1) {
                index1 = getIndex2(&tempNode, word1);
            }
            if(index1 == -1) {
                if(word1[0] == '0') {
                    index1 = -2;
                }
            }
            int index2 = getIndex(inputNames, num1, word2);
            if(index2 == -1) {
                index2 = getIndex2(&tempNode, word2);
            }
            if(index2 == -1) {
                if(word2[0] == '0') {
                    index2 = -2;
                }
            }

            int* inputs = malloc(2 * sizeof(int));
            inputs[0] = index1;
            inputs[1] = index2;

            tempNode = createNode(word3, counter, 2, inputs, 1, tempNode); // when freeing nodes remember to free inputs and names too.

            free(word1);
            free(word2);

            //printNode(tempNode);
            counter++;
        }
        else if(strcmp(word, "XOR") == 0) {
            char* word1 = malloc(15 * sizeof(char));      
            char* word2 = malloc(15 * sizeof(char));
            char* word3 = malloc(15 * sizeof(char));

            fscanf(fp1, "%s", word1);
            fscanf(fp1, "%s", word2);
            fscanf(fp1, "%s", word3);

            if(word3[0] == 'O' && word3[1] == 'U' && word3[2] == 'T') {
                outputIndexes[getIndex(outputNames, num2, word3)] = counter;
            }

            int index1 = getIndex(inputNames, num1, word1);
            if(index1 == -1) {
                index1 = getIndex2(&tempNode, word1);
            }
            if(index1 == -1) {
                if(word1[0] == '0') {
                    index1 = -2;
                }
            }
            int index2 = getIndex(inputNames, num1, word2);
            if(index2 == -1) {
                index2 = getIndex2(&tempNode, word2);
            }
            if(index2 == -1) {
                if(word2[0] == '0') {
                    index2 = -2;
                }
            }

            int* inputs = malloc(2 * sizeof(int));
            inputs[0] = index1;
            inputs[1] = index2;

            tempNode = createNode(word3, counter, 2, inputs, 2, tempNode); // when freeing nodes remember to free inputs and names too.

            free(word1);
            free(word2);

            //printNode(tempNode);
            counter++;
        }
        else if(strcmp(word, "NOT") == 0) {
            char* word1 = malloc(15 * sizeof(char));      
            char* word2 = malloc(15 * sizeof(char));

            fscanf(fp1, "%s", word1);
            fscanf(fp1, "%s", word2);

            if(word2[0] == 'O' && word2[1] == 'U' && word2[2] == 'T') {
                outputIndexes[getIndex(outputNames, num2, word2)] = counter;
            }

            int index1 = getIndex(inputNames, num1, word1);
            if(index1 == -1) {
                index1 = getIndex2(&tempNode, word1);
            }
            if(index1 == -1) {
                if(word1[0] == '0') {
                    index1 = -2;
                }
            }

            int* inputs = malloc(1 * sizeof(int));
            inputs[0] = index1;

            tempNode = createNode(word2, counter, 1, inputs, 3, tempNode);

            free(word1);
            //printNode(tempNode);
            counter++;
        }
        else if(strcmp(word, "DECODER") == 0) {
            //int numOfWords = -1;
            int decoderSize = 1;
            fscanf(fp1, "%d", &decoderSize);

            // while((decoderSize + (1 << decoderSize)) != numOfWords) {
            //     decoderSize++;
            // }

            int* inputs = malloc(decoderSize * sizeof(int));
            char* tempWord = malloc(15 * sizeof(char));

            for(int i = 0; i < decoderSize; i++) {
                fscanf(fp1, "%s", tempWord);
                int tempIndex = getIndex(inputNames, num1, tempWord);
                if(tempIndex == -1) {
                    tempIndex = getIndex2(&tempNode, tempWord);
                }
                if(tempIndex == -1) {
                    if(tempWord[0] == '0') {
                        tempIndex = -2;
                    }
                }
                inputs[i] = tempIndex;
            }

            free(tempWord);

            for(int i = 0; i < (1 << decoderSize); i++) {
                char* tempWord2 = malloc(15 * sizeof(char));

                fscanf(fp1, "%s", tempWord2);
                bool* binary = toBinary(i, (1 << (decoderSize-1)), decoderSize);

                if(tempWord2[0] == 'O' && tempWord2[1] == 'U' && tempWord2[2] == 'T') {
                    outputIndexes[getIndex(outputNames, num2, tempWord2)] = counter;
                }

                int* inputs2 = malloc(decoderSize * sizeof(int));

                for(int j = 0; j < decoderSize; j++) {
                    inputs2[j] = inputs[j];
                }

                tempNode = createNode(tempWord2, counter, decoderSize, inputs2, 4, tempNode);

                for(int j = 0; j < decoderSize; j++) {
                    if(!binary[j]) {
                        tempNode->oppositeInputs[j] = true;
                    }
                }

                free(binary);
                //printNode(tempNode);

                counter++;
            }
            free(inputs);
        }
        else if(strcmp(word, "MULTIPLEXER") == 0) {
            int multiplexerSize = 1;
            fscanf(fp1, "%d", &multiplexerSize);
            int selectorSize = logBase2(multiplexerSize * 1.0);

            int* inputs = malloc((multiplexerSize+selectorSize) * sizeof(int));
            char* tempWord = malloc(15 * sizeof(char));

            for(int i = 0; i < (multiplexerSize+selectorSize); i++) {
                fscanf(fp1, "%s", tempWord);

                int tempIndex = getIndex(inputNames, num1, tempWord);
                if(tempIndex == -1) {
                    tempIndex = getIndex2(&tempNode, tempWord);
                }
                if(tempIndex == -1) {
                    if(tempWord[0] == '0') {
                        tempIndex = -2;
                    }
                }
                inputs[i] = tempIndex;
            }

            fscanf(fp1, "%s", tempWord);

            if(tempWord[0] == 'O' && tempWord[1] == 'U' && tempWord[2] == 'T') {
                outputIndexes[getIndex(outputNames, num2, tempWord)] = counter;
            }

            tempNode = createNode(tempWord, counter, (multiplexerSize+selectorSize), inputs, 5, tempNode);

            //printNode(tempNode);
            counter++;
        }
        else if(word[0] == 'G') {               
            gIndexes[gcounter] = counter;
            gcounter++;
            int numOfWords = -1;
            fscanf(fp1, "%d", &numOfWords);
            if(numOfWords == 6 || numOfWords == 11 || numOfWords == 20 || numOfWords == 37 || numOfWords == 70 || numOfWords == 135) { // INPUT IS A DECODER
                int decoderSize = 1;
                while((decoderSize + (1 << decoderSize)) != numOfWords) {
                    decoderSize++;
                }

                //printf("DECODER SIZE: %d\n", decoderSize);

                int* inputs = malloc(decoderSize * sizeof(int));
                char* tempWord = malloc(15 * sizeof(char));

                for(int i = 0; i < decoderSize; i++) {
                    fscanf(fp1, "%s", tempWord);
                    int tempIndex = getIndex(inputNames, num1, tempWord);
                    if(tempIndex == -1) {
                        tempIndex = getIndex2(&tempNode, tempWord);
                    }
                    if(tempIndex == -1) {
                        if(tempWord[0] == '0') {
                            tempIndex = -2;
                        }
                    }
                    inputs[i] = tempIndex;
                }

                free(tempWord);

                for(int i = 0; i < (1 << decoderSize); i++) {
                    char* tempWord2 = malloc(15 * sizeof(char));

                    fscanf(fp1, "%s", tempWord2);
                    bool* binary = toBinary(i, (1 << (decoderSize-1)), decoderSize);

                    if(tempWord2[0] == 'O' && tempWord2[1] == 'U' && tempWord2[2] == 'T') {
                        outputIndexes[getIndex(outputNames, num2, tempWord2)] = counter;
                    }

                    int* inputs2 = malloc(decoderSize * sizeof(int));

                    for(int j = 0; j < decoderSize; j++) {
                        inputs2[j] = inputs[j];
                    }

                    tempNode = createNode(tempWord2, counter, decoderSize, inputs2, 4, tempNode);
                    for(int j = 0; j < decoderSize; j++) {
                        if(!binary[j]) {
                            tempNode->oppositeInputs[j] = true;
                        }
                    }

                    free(binary);
                    //printNode(tempNode);

                    counter++;
                }
                free(inputs);
            }
            else if(numOfWords == 7 || numOfWords == 12 || numOfWords == 21 || numOfWords == 38 || numOfWords == 71 || numOfWords == 136) { // INPUT IS A MULTIPLEXER
                int selectorSize = 1;
                while((selectorSize + (1 << selectorSize) + 1) != numOfWords) {
                    selectorSize++;
                }
                int multiplexerSize = (1 << selectorSize);

                int* inputs = malloc((multiplexerSize+selectorSize) * sizeof(int));
                char* tempWord = malloc(15 * sizeof(char));

                for(int i = 0; i < (multiplexerSize+selectorSize); i++) {
                    fscanf(fp1, "%s", tempWord);

                    int tempIndex = getIndex(inputNames, num1, tempWord);
                    if(tempIndex == -1) {
                        tempIndex = getIndex2(&tempNode, tempWord);
                    }
                    if(tempIndex == -1) {
                        if(tempWord[0] == '0') {
                            tempIndex = -2;
                        }
                    }
                    inputs[i] = tempIndex;
                }

                fscanf(fp1, "%s", tempWord);

                if(tempWord[0] == 'O' && tempWord[1] == 'U' && tempWord[2] == 'T') {
                    outputIndexes[getIndex(outputNames, num2, tempWord)] = counter;
                }

                tempNode = createNode(tempWord, counter, (multiplexerSize+selectorSize), inputs, 5, tempNode);

                //printNode(tempNode);
                counter++;
            }
            else {
                int* inputs = malloc((numOfWords-1) * sizeof(int));
                char* tempWord = malloc(15 * sizeof(char));

                //printf("NUM OF WORDS: %d\n\n", numOfWords);

                for(int i = 0; i < numOfWords-1; i++) {
                    fscanf(fp1, "%s", tempWord);
                    int tempIndex = getIndex(inputNames, num1, tempWord);
                    if(tempIndex == -1) {
                        tempIndex = getIndex2(&tempNode, tempWord);
                    }
                    if(tempIndex == -1) {
                        if(tempWord[0] == '0') {
                            tempIndex = -2;
                        }
                    }
                    inputs[i] = tempIndex;
                }
                fscanf(fp1, "%s", tempWord);

                if(tempWord[0] == 'O' && tempWord[1] == 'U' && tempWord[2] == 'T') {
                    outputIndexes[getIndex(outputNames, num2, tempWord)] = counter;
                }

                tempNode = createNode(tempWord, counter, numOfWords-1, inputs, 0, tempNode);

                //printNode(tempNode);

                counter++;
            }
        }
        else {
            //printf("word: %s\n", word);
            //printf("ERROR!\n");
            break;
        }
        //char a = fgetc(fp1);
        //break;
    }

    //printf("I FINISHED THE FILE!!!!\n");

    // for(int i = 0; i < gcounter; i++) {
    //     printf("gIndex%d: %d\n", i, gIndexes[i]);
    // }

    bool* tempValues = malloc(counter * sizeof(bool));

    //printGNodes(&tempNode, gIndexes, gcounter);

    bool validSoFar2 = true;
    //printf("2^n: %d\n", (1 << num1));
    for(int i = 0; i < (1 << num1); i++) {
        validSoFar2 = runCircuit(inputValues, num1, &tempNode, outputValues, i, tempValues, counter, outputIndexes, num2);
        if(!validSoFar2) {
            //printf("HEARTBREAKER!\n");
            break;
        }
    }

    //return EXIT_SUCCESS;
    //if(validSoFar2);
    bool keepGoing;
    if(!validSoFar2) {
        keepGoing = updateGs(&tempNode, gIndexes, gcounter);
    }
    

    //printf("keepgoing: %d\n", keepGoing);
    //printf("validSoFar2: %d\n", validSoFar2);

    //printGNodes(&tempNode, gIndexes, gcounter);

    while(keepGoing) {
        bool validSoFar = true;
        for(int i = 0; i < (1 << num1); i++) {
            validSoFar = runCircuit(inputValues, num1, &tempNode, outputValues, i, tempValues, counter, outputIndexes, num2);
            if(!validSoFar) {
                //printf("BING BONG\n");
                break;
            }
        }
        if(validSoFar) {
            //printf("HEYOOO\n");
            break;
        }
        keepGoing = updateGs(&tempNode, gIndexes, gcounter);
        if(!keepGoing) {
            printf("INVALID\n");
            break;
        }
        //print
    }

    //printGNodes(&tempNode, gIndexes, gcounter);
    // printf("gIndexes: ");
    // for(int i = 0; i < gcounter; i++) {
    //     printf("%d, ", gIndexes[i]);
    // }
    // printf("\n");

    if(keepGoing || validSoFar2) {

    for(int i = 0; i < gcounter; i++) {
        //printf("1\n");
        //printf("%d\n", gIndexes)
        struct node* ptr = tempNode;
        //printf("GINDEX: %d\n", gIndexes[i]);
        while(ptr->index != gIndexes[i]) {
            ptr = ptr->next;
        }
        //printf("PTR.OPP: %d\n", ptr->operation);
        /*for(int j = 0; j < gIndexes[i]-(num1-1); j++) {
            ptr = ptr->next;
            //printf("PTR NAME: %s\n", ptr->name);
        }*/
        //printf("PTR NAME: %s\n", ptr->name);
        char* output;
        if(ptr->operation == 0) {
            output = "OR";
        }
        else if(ptr->operation == 1) {
            output = "AND";
        }
        else if(ptr->operation == 2) {
            output = "XOR";
        }
        else if(ptr->operation == 3) {
            output = "NOT";
        }
        else if(ptr->operation == 4) {
            output = "DECODER";
        }
        else if(ptr->operation == 5) {
            output = "MULTIPLEXER";
        }
        printf("G%d %s\n", (i+1), output);
    }
    }

    //printf("\n");

    free(word);
    for(int i = 0; i < num1; i++) {
        //printf("%s", inputNames[i]);
        free(inputNames[i]);
        for(int j = 0; j < (1 << num1); j++) {
            //printf(" %d", inputValues[i][j]);
        }
        //printf("\n");
        free(inputValues[i]);
    }
    free(inputNames);
    free(inputValues);
    for(int i = 0; i < num2; i++) {
        //printf("%s", outputNames[i]);
        free(outputNames[i]);
        for(int j = 0; j < (1 << num1); j++) {
            //printf(" %d", outputValues[i][j]);
        }
        //printf("\n");
        free(outputValues[i]);
    }
    free(outputNames);
    free(outputValues);

    free(gIndexes);
    free(tempValues);
    free(outputIndexes);

    for(int i = counter-num1-1; i >=0; i--) {
        struct node* temp = tempNode;
        for(int j = 0; j < i; j++) {
            temp = temp->next;
        }
        free(temp->oppositeInputs);
        free(temp->inputs);
        free(temp->name);
        free(temp);
    }


    //struct node* temp = tempNode;
    //printf("NODE: %s\n", temp->name);
    //printf("NODE: %s\n", temp->next->name);
    //printf("COUNTER: %d\n", counter-num1);
    /*while(tempNode) {
        while(temp->next) {
            printf("NODE->NEXT: %s\n", temp->next->name);
            temp = temp->next;
        }
        printf("NODE TO DELETE: %s\n", temp->name);
        free(temp->inputs);
        free(temp->name);
        free(temp);
        temp = tempNode;
        printf("NODE: %s\n", temp->name);
        printf("HEAD: %s\n", tempNode->name);
    }*/

    return EXIT_SUCCESS;
}