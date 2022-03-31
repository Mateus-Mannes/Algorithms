#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(){

    // get te list
    char listStr[100];
    printf("Your list (1, 2, 3 ...): ");
    fgets(listStr, sizeof(listStr), stdin);

    // count elements
    char* tempstr = calloc(strlen(listStr), sizeof(char));
    strcpy(tempstr, listStr);
    int listLenght = 0;
    char *token;
    token = strtok(tempstr, ", ");
    while(token != NULL){
        listLenght++;
        token = strtok(NULL, ", ");
    }
    
    // pass elements to array
    int arr[listLenght];
    int i = 0;
    token = strtok(listStr, ", ");
    while(token != NULL){
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, ", ");
    }

    //sort asc
    for(int i = 1; i < listLenght; i++){
        int key = arr[i];
        int prevElement = i - 1;
        while (prevElement >= 0 && arr[prevElement] > key){
            arr[prevElement + 1] = arr[prevElement];
            prevElement--;
        }
        arr[prevElement + 1] = key;
    }

    for(int i = 0; i < listLenght; i++){
        printf("%d, ", arr[i]);
    }

    printf("\n");

    // sort desc
    for(int i = listLenght -2; i >= 0; i--){
        int key = arr[i];
        int nextElement = i + 1;
        while (nextElement < listLenght && arr[nextElement] > key){
            arr[nextElement - 1] = arr[nextElement];
            nextElement++;
        }
        arr[nextElement - 1] = key;
    }

    for(int i = 0; i < listLenght; i++){
        printf("%d, ", arr[i]);
    }

}