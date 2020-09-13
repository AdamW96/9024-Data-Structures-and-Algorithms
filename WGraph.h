//
// Created by WZZ on 2020/6/27.
//
#include <stdbool.h>


typedef struct GraphRep * Graph ;

typedef int Vertex;
typedef struct edge{
    Vertex v;
    Vertex w;
} Edge;

Graph newGraph(int v);
bool validV(Graph g,Vertex v);
void insertEdge(Graph g,Edge e);
void removeEdge(Graph g, Edge e);
bool adjacent(Graph g,Vertex x,Vertex y);
void freeGraph(Graph g);
void showGraph(Graph g);
int numOfVertices(Graph g);
