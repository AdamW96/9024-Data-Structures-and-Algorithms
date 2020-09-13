//
// Created by WZZ on 2020/7/1.
//
#include "stdlib.h"
#include "assert.h"
#include "queue.h"

typedef struct node{
    int data;
    struct node *next;
} NodeT;

typedef struct QueueRep{
    int length;
    NodeT *head;
    NodeT *tail;
} QueueRep;

//set up a new empty queue;
queue newQueue(){
    queue Q=malloc(sizeof(struct QueueRep));
    Q->length=0;
    Q->head=NULL;
    Q->tail=NULL;
    return Q;
}

//remove queue
void dropQueue(queue Q){
    NodeT *curr=Q->head;
    while(curr !=NULL){
        NodeT *temp=curr->next;
        free(curr);
        curr=temp;
    }
    free(Q);
}

//check whether queue is empty
int QueueIsEmpty(queue Q){
    return (Q->length==0);
}

//insert an int at end of queue
void QueueEnqueue(queue Q,int i){
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data=i;
    new->next=NULL;
    if(Q->tail!=NULL){
        Q->tail->next=new;
        Q->tail=new;
        Q->length++;
    }else{
        Q->tail=new;
        Q->head=new;
        Q->length++;
    }
}

//remove the first element from the queue
int QueueDequeue(queue Q){
    assert(Q->length>0);
    NodeT *p=Q->head;
    Q->head=p->next;
    if(Q->head==NULL){
        Q->tail=NULL;
    }Q->length--;
    int d=p->data;
    free(p);
    return d;
}