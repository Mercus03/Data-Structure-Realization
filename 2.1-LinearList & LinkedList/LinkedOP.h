#ifndef LINKEDOP_H
#define LINKEDOP_H
#include "StructNode.h"
#include <stdio.h>

int Length(LList LPtrl){
    LList p = LPtrl; /* 指向表的第一个结点 */
    int length = 0;
    while(p){
        p = p->Next;
        length++;   /* 当前p指向的是第x个结点 */
    }
    return length;
}

/* 按序数查找 */
LList FindKth(int K, LList LPtrl){
    int i = 1;  /* Kth从1开始数 */
    LList p = LPtrl;
    while(p != NULL && i < K ){
        p = p->Next;
        i++;
    }
    if(i == K) return p; /* 返回第K个，返回指针 */
    else return NULL; /* 否则返回空 */
}

/* 按值查找 */
LList FindX(ElementType X, LList LPtrl){
    LList p = LPtrl;
    while(p != NULL && p->Data != X){
        p = p->Next;
    }
    return p;
}

LList Insert(ElementType X, int i, LList LPtrl){
    LList p,s;
    if( i==1){  /* 新结点插入在表头 */
        s = (LList)malloc(sizeof(struct LinkedNode));   /* 申请、填装结点 */
        s->Data = X;
        s->Next = LPtrl;
        return s;   /* 返回新表头指针 */
    }

    p = FindKth(i-1, LPtrl);
    if(p == NULL){
        printf("参数错误");
        return NULL;
    }else{
        s = (LList)malloc(sizeof(struct LinkedNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;    /* 新结点插入在第i-1个结点后 */
        return LPtrl;
    }
}

LList Delete(int i, LList LPtrl){
    LList p,s;
    if( i==1 ){  /* 删除表头结点 */
        s = LPtrl;   
        if(LPtrl != NULL)  LPtrl = LPtrl->Next;
        else return NULL;
        free(s);
        return LPtrl;
    }

    LList p = FindKth(i-1, LPtrl);
    if(p == NULL){
        printf("第%d个元素不存在", i-1);
        return NULL;
    }else if(p->Next == NULL){
        printf("第%d个元素不存在", i);
        return NULL;
    }else{
        s = p->Next;    /* s指向第i个结点 */
        p->Next = s->Next;
        free(p);
        return LPtrl;
    }
}

#endif