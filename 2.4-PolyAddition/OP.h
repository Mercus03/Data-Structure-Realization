#ifndef OP_H
#define OP_H
#include "StructNode.h"

int Compare(int i1, int i2){
    if(i1 > i2){
        return 1;
    }else if(i1 < i2){
        return -1;
    }else{
        return 0;
    }
}

void Attach(int coef, int expon, Polynomial *pRear){
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = coef;
    P->expon = expon;
    P->Next = NULL;
    (*pRear)->Next = P;
    *pRear = P;

}


Polynomial PolyAdd(Polynomial P1,Polynomial P2){
    PolyNode *front, *rear, *temp;
    int sumCoef;
    rear = (PolyNode *)malloc(sizeof(struct PolyNode));
    front = rear;   /* 由front记录结果多项式链表头结点 */
    
    while(P1 && P2){
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
            /* code */
            break;
        }
    }
    for(;P1; P1 = P1->Next) Attach(P1->coef, P1->expon, &rear);
    for(;P2; P2 = P2->Next) Attach(P2->coef, P2->expon, &rear);
    rear->Next = NULL;
    temp = front;
    front = front->Next;
    free(temp); /* 释放空表头结点 */
    return front;

}

#endif