//
// Created by WZZ on 2020/6/27.
//
#include "stdbool.h" 
#include "stdlib.h"
#include "WGraph.h"
#include "stdio.h"
#include "assert.h"
typedef struct GraphRep{
    int **edges;
    int nV;
    int nE;
} GraphRep;

Graph newGraph(int v){
    assert(v >=0);
    int i;
    Graph g=malloc(sizeof(GraphRep));
    assert(g!=NULL);
    g->nV=v;
    g->nE=0;
    g->edges=malloc(v*sizeof(int *));
    for(i=0;i<v;i++)
        g->edges[i]=malloc(v*sizeof(int));
    return g;
}
bool validV(Graph g,Vertex v){
    return(g!=NULL&&v>=0&&v<g->nV);
}

int numOfVertices(Graph g){
    return g->nV;
}

void insertEdge(Graph g,Edge e){
    assert(g!=NULL&&validV(g,e.v)&&validV(g,e.w));
    if (g->edges[e.v][e.w]!=1&&g->edges[e.w][e.v]!=1){
        g->edges[e.v][e.w]=1;
        g->edges[e.w][e.v]=1;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e){
    assert(g!=NULL &&validV(g,e.v)&&validV(g,e.w));
    if(g->edges[e.v][e.w]){
        g->edges[e.v][e.w]=0;
        g->edges[e.w][e.v]=0;
        g->nE--;
    }
}

bool adjacent(Graph g,Vertex x,Vertex y){
    assert(g!=NULL&&validV(g,x)&&validV(g,y));
    return(g->edges[x][y]==1);
}

void freeGraph(Graph g){
    assert(g!=NULL);
    for(int i=0; i<g->nV;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

void showGraph(Graph g){
    assert(g!=NULL);
    int i,j;
    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for(i=0;i<g->nV;i++)
        for(j=i+1;j<g->nV;j++)
            if(g->edges[i][j])
                printf("Edge %d - %d\n", i,j);

}