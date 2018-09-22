/*
    Mealy Machine to find pattern 100 in a string
*/

#include <stdio.h>
#include <stdlib.h>

void stateStatus(int *state, int curr){
    *state = curr;
    printf("\nCurrrent State : q%d\n", *state);
}

void output(int *arr, int pos, int res){
    arr[pos] = res;
}

void Mealy(int *arr, int num, int *state){
    int i;

    stateStatus(state, 0);

    for(i = 0; i < num; ++i){
        switch(*state){
            case 0: if(arr[i]){
                        stateStatus(state, 1);
                        output(arr, i, 0);
                    }else{
                        stateStatus(state, 0);
                        output(arr, i, 0);
                    }break;
            case 1: if(arr[i]){
                        stateStatus(state, 1);
                        output(arr, i, 0);
                    }else{
                        stateStatus(state, 2);
                        output(arr, i, 0);
                    }break;;
            case 2: if(arr[i]){
                        stateStatus(state, 1);
                        output(arr, i, 0);
                    }else{
                        stateStatus(state, 0);
                        output(arr, i, 1);
                    }
        }
    }
}

void input_array(int *arr, int num){
    int i;

    printf("\nEnter String : ");
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }
}

void output_array(int *arr, int num){
    int i;

    printf("\nResultant Array : ");

    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

void main(){
    int state, num;

    printf("\nEnter Length of String : ");
    scanf("%d", &num);

    int *arr = (int *) malloc(num * sizeof(int));

    input_array(arr, num);

    Mealy(arr, num, &state);

    output_array(arr, num);   
}