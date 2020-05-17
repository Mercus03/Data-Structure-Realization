#ifndef OP_H
#define OP_H
#include "PolyNode.h"

int Compare(int i1, int i2){
    if(i1 > i2){
        return 1;
    }else if(i1 < i2){
        return -1;
    }else{
        return 0;
    }
}

/* 拷贝这一项的系数和指数 */
void Attach(int coef, int expon, Polynomial *pRear){    
/* pRear是指针的指针，因为C语言是函数参数值传递，想要修改指针就要用二级指针(修改rear指针的内容) */
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = coef;
    P->expon = expon;
    P->Next = NULL;
    (*pRear)->Next = P;
    *pRear = P; /* 修改pRear值 */

}


Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    PolyNode *front, *rear, *temp;
    int sumCoef;
    rear = (PolyNode *)malloc(sizeof(struct PolyNode));
    front = rear;   /* 由front记录结果多项式链表头结点 */
    
    while(P1 && P2){    /* 当两个多项式都有非零项待处理时 */
        switch (Compare(P1->expon, P2->expon))
        {
        case 1:
            Attach(P1->coef, P1->expon, &rear); 
            P1 = P1->Next;
            break;
        case -1:
            Attach(P2->coef, P2->expon, &rear);
            P1 = P1->Next;
            break;
        case 0:
            sumCoef = P1->coef + P2->coef;
            if(sumCoef) Attach(sumCoef, P1->expon, &rear);
            P1 = P1->Next;
            P2 = P2->Next;
            break;
        }
    }

    /* 将未处理完的另一个多项式的所有节点依次拷贝 */
    for(; P1; P1 = P1->Next) Attach(P1->coef, P1->expon, &rear);
    for(; P2; P2 = P2->Next) Attach(P2->coef, P2->expon, &rear);
    rear->Next = NULL;
    temp = front;
    front = front->Next;    /* 令front指向结果多项式第一个非零项 */
    free(temp); /* 释放空表头结点 */
    return front;
}

#endif