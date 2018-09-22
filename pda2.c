/*
    Program for L={W C W^T | W belongs to {a, b}^*}
*/

#include<stdio.h>
#include<stdlib.h>

int STACK[100], POINTER = -1;

void stateStatus(int *state, int curr){
    *state = curr;
    printf("\nCurrrent State : q%d\n", *state);
}

void notAccepted(char *error){
    printf("\n%s : String Not Accepted\n\n", error);
    exit(-1);
}

void push(char var){
    if(POINTER >= 100){
        printf("\nSTACK OVERFLOW");
        exit(-1);
    }

    STACK[++POINTER] = var;
}

char pop(){
    if(POINTER <= -1){
        notAccepted("STACK UNDERFLOW");
    }
    
    return STACK[POINTER--];
}

void language_check(char *arr, int *state){
    int i;

    for(i = 0; arr[i]; i++){
        if(*state == 0){
            if(arr[i] == 'c'){
                stateStatus(state, 1);
            }else{
                push(arr[i]);
                stateStatus(state, 0);
            }
        }else if(*state == 1){
            if(arr[i] == 'c'){
                notAccepted("c APPEARED MORE THAN 1 TIME");
            }

            if(pop() == arr[i]){
                stateStatus(state, 1);
            }else{
                notAccepted("TRANSPOSE NOT FOUND");
            }
        }
    }

    stateStatus(state, 2);
}

void main(){
    printf("\nProgram for L={W C W^T | W belongs to {a, b}^*\n");

    int state = 0;
    char *arr;

    printf("\nEnter String : ");
    scanf("%s", arr);

    language_check(arr, &state);

    printf("\nString Accepted\n\n");
}