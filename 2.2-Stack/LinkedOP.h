#ifndef LINKED_H
#define LINKED_H
#include "StructStack.h"
#include <stdio.h>
#include <stdlib.h>

LStack CreateStack(){
    LStack S;
    S = (LStack)malloc(sizeof(struct LSNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(LStack S){
    return (S->Next == NULL);   /* 若空返回1,否则返回0*/
}


/* 
    带头结点的链栈：
    头节点里面也有数据内容，一般的内容是这个链表有多大；
    你也可以认为它没有数据内容，但是它肯定有指针内容。
*/
void Push(LStack S, ElementType item){
    /* 链表表头插入一个结点 */
    struct LSNode *TmpCell;
    TmpCell = (struct LSNode *)malloc(sizeof(struct LSNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    /* S指向头结点，S->NEXT指向新插入的结点 */
}

ElementType Pop(LStack S){
    struct LSNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");
        return NULL;
    }else{
        FirstCell = S->Next;    /* 第一个元素 */
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}


#endif