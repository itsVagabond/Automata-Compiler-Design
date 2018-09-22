/*
    DFA for a string having {awa : w belongs to {a, b}*}
*/

#include <stdio.h>

void stateStatus(int *state, int curr){
    *state = curr;
    printf("\nCurrrent State : q%d\n", *state);
}

void DFA(char *arr, int *state){
    int i;

    stateStatus(state, 0);

    for(i = 0; arr[i]; ++i){
        switch(*state){
            case 0: if(arr[i] == 'a'){
                        stateStatus(state, 1);
                    }else{
                        stateStatus(state, 3);
                    }break;
            case 1: if(arr[i] == 'a' ){
                        stateStatus(state, 2);
                    }else{
                        stateStatus(state, 1);
                    }break;;
            case 2: if(arr[i] == 'a'){
                        stateStatus(state, 2);
                    }else{
                        stateStatus(state, 1);
                    }break;
            case 3: if(arr[i] == 'a' || arr[i] == 'b'){
                        stateStatus(state, 3);
                    }
        }
    }

    if(*state == 2){
        printf("\nString Accepted\n");
    }else{
        printf("\nString Not Accepted\n");
    }
}

void main(){
    char arr[20];
    int state = 0;

    printf("\nEnter String : ");
    scanf("%s", &arr);

    DFA(arr, &state);
}  