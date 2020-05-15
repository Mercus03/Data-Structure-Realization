#ifndef LINKED_H
#define LINKED_H
#include "StructQueue.h"
#include <stdio.h>
#include <stdlib.h>

/* front设置在链表 头or尾：
front 要做删除操作；rear要做插入操作；
链表表头做插入或者删除都方便；
链表表尾不好做删除操作，因为删除了不知道上一个元素在哪里 */

void AddLQ(LQueue Q, ElementType item){
    struct Node* newItem;
    if(Q->rear->Next == Q->front){
        printf("队列已满");
        return;
    }else{
        newItem = (struct Node*)malloc(sizeof(struct LQNode));
        newItem->Data = item;
        Q->rear = newItem;
    }
}

ElementType DeleteLQ(LQueue Q){
    ElementType output;
    struct Node *frontCell;
    if(Q->rear == Q->front){
        printf("队列空");
        return NULL;
    }
    frontCell = Q->front;
    output = frontCell->Data;
    if(Q->front == Q->rear){    /* 队列只有一个元素 */
        Q->front = Q->rear =NULL;   /* 删除后队列置为空 */
    }else{
        Q->front = Q->front->Next;
    }
    free(frontCell);
    return output;
}

#endif