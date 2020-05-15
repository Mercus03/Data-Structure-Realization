#ifndef OP_H
#define OP_H
#include"StructQueue.h"
#include<stdio.h>

/* 循环队列，仅使用n-1个空间判满/空 */

void AddQ(Queue Q, ElementType item){
    if((Q->rear+1) % MAXSIZE == Q->front ){
        printf("队列满");
        return;
    }
    Q->rear = (Q->rear+1) % MAXSIZE;
    Q->Data[Q->rear] = item;
}

/* 出队列：队首 */
ElementType DeleteQ(Queue Q){
    if(Q->front == Q->rear){
        printf("队列空");
        return NULL;
    }else{
        Q->front = (Q->front+1) % MAXSIZE;
        return Q->Data[Q->front];
    }
}


#endif