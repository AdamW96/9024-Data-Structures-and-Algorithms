//
// Created by WZZ on 2020/6/28.
//
#include "list.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
typedef struct Node{
    int v;
    struct Node*next;
} Node;

Node *makeNode(int n){
    Node *new=malloc(sizeof(struct Node));
    new->v=n;
    new->next=NULL;
    return new;
}
bool inLL(List L, int n) {
    if (L == NULL)
        return false;
    if (L->v == n)
        return true;

    return inLL(L->next, n);
}

List insertLL(List L, int n){
    if(inLL(L,n))
        return L;
    Node *new=makeNode(n);
    new->next=L;
    return new;
}

List deleteLL(List L,int n){
    if(L==NULL)
        return NULL;
    if(L->v==n)
        return L->next;
    L->next=deleteLL(L->next,n);
    return L;
}

void showLL(List L){
    if(L==NULL)
        putchar('\n');
    else{
        if(L->next!=NULL)
        {printf("%d and ",L->v);}
        else printf("%d",L->v);
        showLL(L->next);
    }
}

void freeLL(List L){
    if(L!=NULL){
        freeLL(L->next);
        free(L);
    }
}