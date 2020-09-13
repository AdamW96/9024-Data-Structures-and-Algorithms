//
// Created by WZZ on 2020/6/27.
//
#include "stdbool.h"
#include "WGraph.h"
#include "stdio.h"
#define NODES 6
#define NODE_OF_TEST 1
int componentOf[8];

void dfsComponents(Graph g, int v, int id) {
    componentOf[v] = id;
    Vertex w;
    for (w = 0; w < numOfVertices(g); w++)
        if (adjacent(g, v, w) && componentOf[w] == -1)
            dfsComponents(g, w, id);
}

int main(void) {
    Graph g = newGraph(NODES);
    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 1;
    e.w = 3;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v=2;e.w=4;
    insertEdge(g, e);
    e.v=4;e.w=5;
    insertEdge(g, e);
    e.v=5;e.w=4;
    insertEdge(g, e);
//
    showGraph(g);
    freeGraph(g);
}