//
// Created by WZZ on 2020/6/28.
//
#include "WGraph.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define ENOUGH 10000
typedef struct GraphRep {
    Edge *edges; // array of edges
    int   nV;    // #vertices (numbered 0..nV-1)
    int   nE;    // #edges
    int   n;     // size of edge array
} GraphRep;

Graph newGraph(int v) {
    assert(v >= 0);

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV=v;
    g->nE=0;
    g->n = ENOUGH;
    g->edges = malloc(g->n * sizeof(Edge));
    assert(g->edges != NULL);
    return g;
}

int numOfVertices(Graph g) {
    return g->nV;
}

//it is important to check if two edges are equal;
bool eq(Edge e1,Edge e2){
    if((e1.v==e2.v&&e1.w==e2.w)||(e1.v==e2.w&&e1.w==e2.v))
        return true;
    else return false;
}

void insertEdge(Graph g,Edge e){
    assert(g!=NULL&&g->nE<g->n);
    int i=0;
    while(i<g->nE&&!eq(e,g->edges[i]))
        i++;
    if(i==g->nE){
        g->edges[i]=e;
        g->nE++;}
}
void removeEdge(Graph g,Edge e){
    assert(g!=NULL);
    int i=0;
    while(i<g->nE&&!eq(e,g->edges[i]))
        i++;
    if(i<g->nE){
        g->nE--;
        g->edges[i]=g->edges[g->nE];
    }
}

bool adjacent(Graph g,Vertex x, Vertex y){
    assert(g!=NULL);
    Edge e;
    e.v=x;e.w=y;
    int i=0;
    while(i<g->nE){
        if(eq(e,g->edges[i]))
            return true;
        i++;
    }return false;
}

void showGraph(Graph g){
    assert(g!=NULL);
    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n",g->nE);
    int i;
    for(i=0;i<g->nE;i++){
        printf("Edge %d -> %d\n",g->edges[i].v,g->edges[i].w);
    }
}
void freeGraph(Graph g){
    assert(g!=NULL);
    free(g->edges);
    free(g);
}