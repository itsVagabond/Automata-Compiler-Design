/*
    Program for L={a^n b^n | n >=1 }
*/

#include<stdio.h>
#include<stdlib.h>

int ST[100], POINTER = -1;

void stateStatus(int *state, int curr){
    *state = curr;
    printf("\nCurrrent State : q%d\n", *state);
}

void notAccepted(){
    printf("\nString Not Accepted\n\n");
    exit(-1);
}

void push(char var){
    if(POINTER >= 100){
        printf("\nST OVERFLOW");
        exit(-1);
    }


    ST[++POINTER] = var;
}

void pop(){
    if(POINTER <= -1){
        notAccepted();
    }

    ST[POINTER--] = '@';
}

void language_check(char *arr, int num, int *state){
    int i;

    for(i = 0; i < num; i++){
        if(*state == 0){
            if(arr[i] == 'a'){
                push(arr[i]);
                stateStatus(state, 0);
            }else{
                pop();
                stateStatus(state, 1);
            }
        }else 
        if(*state == 1){
            if(arr[i] == 'b'){
                pop();
                stateStatus(state, 1);
            }else{
                notAccepted();
            }
        }
    }
}

void main(){
    printf("\nProgram for L={a^n b^n | n >=1 }\n");

    int n, state = 0;

    printf("\nEnter Value of n : ");
    scanf("%d", &n);
    
    char *arr = (char *)malloc(sizeof(char) * 2 * n);

    printf("\nEnter String : ");
    scanf("%s", arr);

    language_check(arr, 2*n, &state);

    if(POINTER == -1){
        printf("\nString Accepted\n\n");
    }else{
        notAccepted();
    };
}