// Starting code for Dijkstra's algorithm ... COMP9024 20T2

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"
#include "stdlib.h"

#define VERY_HIGH_VALUE 999999


void dijkstraSSSP(Graph g, Vertex source) {
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s;
    int test_weight;
    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;
    pred[source] = source;
    while(1) {
        Vertex processNode;
        processNode = leavePQueue(dist);
        vSet[processNode] = false;
        for (s = 0; s < nV; s++) {
            if (adjacent(g, s, processNode) && vSet[s]) {
                test_weight=adjacent(g, s, processNode)+dist[processNode];
                if(test_weight<dist[s])
                {dist[s] = test_weight;
                pred[s] = processNode;}
            }
        }
        if(dist[processNode]==VERY_HIGH_VALUE || PQueueIsEmpty()){
            break;
        }
        /* NEEDS TO BE COMPLETED */
    }
    int recording_array[nV];
    int count;
    int i;
    int copy_s;
    for(s=0;s<nV;s++){
        copy_s=s;
        if(s==source){
            printf("%d: distance =0, shortest path: %d\n",s,source);
        }
        else if(s!=source && pred[s]!=-1){
            printf("%d: distance = %d, shortest path: ",s,dist[s]);
            count=0;
            while(pred[copy_s]!=source){
                recording_array[count]=copy_s;
                copy_s=pred[copy_s];
                count++;
            }
            recording_array[count]=copy_s;
            count++;
            printf("%d",source);
            for(i=count-1;i>=0;i--){
                printf("-%d",recording_array[i]);
            }
            printf("\n");
        }
        else printf("%d: no path\n",s);
    }
}

void reverseEdge(Edge *e) {
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void) {
    Edge e;
    int  n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e);               // ensure to add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");
    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}