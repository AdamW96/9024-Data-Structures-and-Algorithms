//
// Created by WZZ on 2020/5/28.
//
#include <stdio.h>
#include<stdlib.h>
#include "IntQueue.h"
#include <assert.h>

typedef struct {
    int item[MAXITEMS];
    int  top;
} queueRep;                   // defines the Data Structure

static queueRep queueObject;  // defines the Data Object

void QueueInit(){            // set up empty stack
    queueObject.top = -1;
}

int QueueIsEmpty() {          // check whether stack is empty
    return (queueObject.top < 0);
}

void QueueEnqueue(int num) {     // insert char on top of stack
    assert(queueObject.top < MAXITEMS-1);
    queueObject.top++;
    int i = queueObject.top;
    queueObject.item[i] = num;
}

int QueueDequeue() {             // remove char from top of stack
    assert(queueObject.top > -1);
    int num = queueObject.item[0];
    queueObject.top--;
    for(int j=0;j<=queueObject.top;j++){
        queueObject.item[j]=queueObject.item[j+1];
    }
    return num;
}

