//
// Created by WZZ on 2020/7/4.
//
#include "WGraph.h"
#include <stdio.h>
#include "assert.h"

#define SIZE 6

void insertionSort(double array[], int sorted_array[],int n) {
    int i;
    for (i = 1; i < n; i++) {
        double element = array[i];                 // for this element ...
        int j = i-1;
        while (j >= 0 && array[j] < element) {  // ... work down the ordered list
            array[j+1]=array[j];
            sorted_array[j+1] = sorted_array[j];               // ... moving elements up
            j--;
        }
        array[j+1]=element;
        sorted_array[j+1] = i;                   // and insert in correct position
    }
}

int main(void) {
    int scanf_vertex;
    int scanf_index;
    int i;
    Edge edge;
    printf("Enter the number of vertices:");
    scanf_index=scanf("%d",&scanf_vertex);
    assert(scanf_index==1 && scanf_vertex>0);
    Graph g=newGraph(scanf_vertex);
    double inDegree[scanf_vertex+1];//set up a double type array about indegree
    double outDegree[scanf_vertex+1];// set up a double type array about outdegree
    double popularityRank[scanf_vertex+1];
    for(i=0;i<scanf_vertex+1;i++){
        inDegree[i]=0;
        outDegree[i]=0;
        popularityRank[i]=0;
    }
    while(1){
        printf("Enter an edge (from):");
        scanf_index=scanf("%d",&edge.v);
        if(scanf_index==0||edge.v<0){
            printf("Done.\n\n");
            break;
        }
        printf("Enter an edge (to):");
        scanf_index=scanf("%d",&edge.w);
        if(scanf_index==0||edge.w<0){
            printf("Done.\n\n");
            break;
        }
        edge.weight=1;
        insertEdge(g,edge);
        inDegree[edge.w]++;//count every node's indegree
        outDegree[edge.v]++;//count every node's outdegree
    }
    for(i=0;i<scanf_vertex;i++){
        if(outDegree[i]==0)
            outDegree[i]=0.5;
        popularityRank[i]=inDegree[i]/outDegree[i];//calculate teh popularityRank array
    }
    double copy_popularityRank[scanf_vertex+1];//set up a copy of array
    for(i=0;i<scanf_vertex;i++){
        copy_popularityRank[i]=popularityRank[i];
    }
    int sorted_array[scanf_vertex];//set up an array about the result of sorting
    for(i=0;i<numOfVertices(g);i++){//initailise the array
        sorted_array[i]=0;
    }
    insertionSort(popularityRank,sorted_array,scanf_vertex);
    printf("Popularity ranking:\n");
    for(i=0;i<scanf_vertex;i++)
        printf("%d %.1f\n",sorted_array[i],copy_popularityRank[sorted_array[i]]);
    freeGraph(g);
}

