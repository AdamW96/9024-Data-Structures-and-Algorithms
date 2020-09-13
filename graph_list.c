//
// Created by WZZ on 2020/6/27.
//
#include "WGraph.h"
#include "list.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
typedef struct GraphRep{
    List *edges;
    int nV;
    int nE;
} GraphRep;

Graph newGraph(int V){
    assert(V >= 0);
    int i;
    Graph g=malloc(sizeof(GraphRep));
    assert(g!=NULL);
    g->nV=V;
    g->nE=0;
    g->edges=malloc(V*sizeof(List));
    assert(g->edges!=NULL);
    for(i=0;i<V;i++)
        g->edges[i]=NULL;
    return g;
}
int numOfVertices(Graph g){
    return g->nV;
}

bool validV(Graph g, Vertex v){
    return (g!=NULL && v>=0 && v < g->nV);
}

void insertEdge(Graph g, Edge e){
    assert(g!=NULL&&validV(g,e.v)&&validV(g,e.w));
    if(!inLL(g->edges[e.v],e.w)){
        g->edges[e.v]=insertLL(g->edges[e.v],e.w);
        g->edges[e.w]=insertLL(g->edges[e.w],e.v);
        g->nE++;
    }
}
void removeEdge(Graph g, Edge e){
    assert(g!=NULL&&validV(g,e.v)&&validV(g,e.w));
    if(inLL(g->edges[e.v],e.w)){
        g->edges[e.v]=deleteLL(g->edges[e.v],e.w);
        g->edges[e.w]=deleteLL(g->edges[e.w],e.v);
        g->nE--;
    }
}

bool adjacent(Graph g,Vertex v, Vertex w){
    assert(g!=NULL && validV(g,v)&&validV(g,w));
    return inLL(g->edges[v],w);
}

void showGraph(Graph g){
    assert(g!=NULL);
    int i;
    printf("Number of vertices: %d\n",g->nV);
    printf("Number of edges: %d\n", g->nE);
    for(i=0;i<g->nV;i++){
        printf("%d -> ",i);
        showLL(g->edges[i]);
    }
}
void freeGraph(Graph g){
    assert(g!=NULL);
    int i;
    for(i=0;i<g->nV;i++){
        freeLL(g->edges[i]);
    }
    free(g->edges);
    free(g);
}