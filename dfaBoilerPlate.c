/*
    DFA for a string {  __CONDITIONS__  }
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
            case 0: if(arr[i] == /* String Constant */){
                        stateStatus(state, /* Next State */);
                    }else{
                        stateStatus(state, /* Next State */);
                    }break;
            case 1: if(arr[i] == /* String Constant */){
                        stateStatus(state, /* Next State */);
                    }else{
                        stateStatus(state, /* Next State */);
                    }break;;
            case 2: if(arr[i] == /* String Constant */){
                        stateStatus(state, /* Next State */);
                    }else{
                        stateStatus(state, /* Next State */);
                    }break;
            case 3: if(arr[i] == /* String Constant */ || arr[i] == /* String Constant */){
                        stateStatus(state, /* Next State*/);
                    }
        }
    }

    if(*state == /* Resultant State*/){
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