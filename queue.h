//
// Created by WZZ on 2020/7/1.
//
typedef struct QueueRep *queue;

queue newQueue();               // set up empty queue
void  dropQueue(queue);         // remove queue
int   QueueIsEmpty(queue);      // check whether queue is empty
void  QueueEnqueue(queue, int); // insert an int at end of queue
int   QueueDequeue(queue);      // remove int from front of queue