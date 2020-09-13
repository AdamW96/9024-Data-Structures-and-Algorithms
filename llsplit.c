//
// Created by WZZ on 2020/7/4.
//
//
// Created by WZZ on 2020/6/5.
//
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

typedef struct node{
    int data;
    struct node *next;
} NodeT;


NodeT *makeNode(int v){
    NodeT *new=malloc(sizeof(NodeT));
    assert(new!=NULL);
    new->data=v;
    new->next=NULL;
    return new;
}

void freeLL(NodeT *list){
    if(list!=NULL){
        NodeT *p, *temp;
        p=list;
        while(p!=NULL){
            temp=p->next;
            free(p);
            p=temp;
        }}
}
void showLL(NodeT *list){
    NodeT *p=list;
    if(list->next!=NULL){
        printf("%d",p->data);
        p=p->next;
        while(p!=NULL){
            printf("-->%d",p->data);
            p=p->next;}
    }else printf("%d",p->data);
}

NodeT *joinLL(NodeT *list, int v){
    NodeT *new=makeNode(v);
    NodeT *temp=list;
    if(list!=NULL){
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=new;

    }else list=new;
    return list;
}


int main(int argc, char *argv[])
{   int number;
    int scanf_index;
    NodeT *all=NULL;
    printf("Enter an integer:");
    scanf_index=scanf("%d",&number);
    if(scanf_index==0){printf("Done.");
        return 0;}
    else{all=makeNode(number);}
    while(1){
        printf("Enter an integer:");
        scanf_index=scanf("%d",&number);
        if(scanf_index==0){
            printf("Done. List is ");
            showLL(all);
            break;}
        else{joinLL(all,number);}
    }
    NodeT *slowp=all;
    NodeT *fastp=all->next;
    while(fastp!=NULL && fastp->next!=NULL){
        slowp=slowp->next;
        fastp=fastp->next->next;
    }
    NodeT *secondlsit=slowp->next;
    slowp->next=NULL;
    printf("\nFirst part is ");
    showLL(all);
    if(secondlsit!=NULL){
        printf("\nSecond part is ");
        showLL(secondlsit);}
    freeLL(all);
    freeLL(secondlsit);
}
