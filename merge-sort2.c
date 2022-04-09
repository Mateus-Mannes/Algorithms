#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int* arr;

// merge arr[p ... q] and arr[q + 1 ... r]
void merge(p, q, r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[q + 1 + j];
    }

    int i = 0;
    int j = 0;

    for(int k =p; k <= r; k++){
        if(L[i] <= R[j] && i < n1 && j < n2){
            arr[k] = L[i];
            i++;
        }
        else if(L[i] > R[j] && i < n1 && j < n2){
            arr[k] = R[j];
            j++;
        }
        else if(i >= n1){
            arr[k] = R[j];
            j++;
        }
        else{
            arr[k] = L[i];
            i++;
        }
    }
}

void mergeSort(int p, int r){
    int q;
    if(p < r){
        q = ceil((double)(p + r + 1)/2.0) - 1;
        mergeSort(p, q);
        mergeSort(q + 1, r);
        merge(p, q, r);
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

    mergeSort(0, listLenght - 1);
    for(int i = 0; i < listLenght; i++){
        printf("%d, ", arr[i]);
    }
    free(arr);
}
