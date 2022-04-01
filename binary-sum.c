#include <stdio.h>

int main(){
    int A[] = {0, 1, 0, 1, 1, 0, 1, 1};
    int B[] = {0, 1, 1, 0, 0, 0, 0, 1};
    int C[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int last = 0;
    for(int i = 7; i >= 0; i--){
        int sum = A[i] + B[i] + last;
        if(sum == 0 || sum == 1){
            C[i] = sum;
            last = 0;
        }
        else if (sum == 2){
            C[i] = 0;
            last = 1;
        }else{
            C[i] = 1;
            last = 1;
        }
    }

    for(int i =0; i < 8 ; i++){
        printf("%d", C[i]);
    }
        
}
