//
// Created by WZZ on 2020/6/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "IntStack.h"
#define MAXITEMS 10

int main(void) {
    int n;
    char str[BUFSIZ];
    StackInit();
    printf("Enter a number: ");
    scanf("%s", str);
    if ((n = atoi(str)) > 0) {    // convert to int and test if positive
        while(n>0){
            int mod = n%2;
            StackPush(mod+'0');
            n/=2;
        }
    }
    while(!StackIsEmpty()){
        char k=StackPop();
        printf("%c",k);
    }
    printf("\n");

    /* NEEDS TO BE COMPLETED */

    return 0;
}


