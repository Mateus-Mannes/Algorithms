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

    int key;
    //sort asc
    for(int i = 0; i < listLenght; i++){
       key = arr[i];
       int jcpy = i;
       for(int j = i + 1; j < listLenght; j++){
           if(arr[j] < key){
               key = arr[j];
               jcpy = j;
           }
       }
       arr[jcpy] = arr[i];
       arr[i] = key;
    }

    for(int i = 0; i < listLenght; i++){
        printf("%d, ", arr[i]);
    }

   

}