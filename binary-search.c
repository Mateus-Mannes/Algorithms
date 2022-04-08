#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int serachNumber;
int* arr;


void binarySearch(int middle, int start,int end){
    int newEnd;
    int newStart;
    if(start == end && arr[middle] != serachNumber){
        printf("not found");
    }
    else if(arr[middle] == serachNumber){
        printf("%d, %d",arr[middle], middle);
    }else if (arr[middle] > serachNumber){
        newStart = start;
        newEnd = middle - 1;
        binarySearch( ceil(newStart + (newEnd - newStart)/2.0), newStart, newEnd);
    } else if (arr[middle] < serachNumber){
        newStart = middle + 1;
        newEnd = end;
        binarySearch( ceil(newStart + (newEnd - newStart)/2.0), newStart, newEnd);
    }
}

int main(){
    // get te list
    char* listStr[100];
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
    arr = malloc(sizeof(int) * listLenght);
    int i = 0;
    token = strtok(listStr, ", ");
    while(token != NULL){
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, ", ");
    }

    //sort asc (insertion sort)
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

    // binary-search
    printf("Search Number: ");
    scanf("%d", &serachNumber);
    int middle;
    middle = ceil(listLenght/2.0) - 1;
    printf("%d %d %d\n", middle, listLenght,serachNumber);
    binarySearch(middle, 0, listLenght - 1);

    free(arr);
}
