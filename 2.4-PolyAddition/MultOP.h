#ifndef MULTOP_H
#define MULTOP_H
#include "PolyNode.h"
#include "AddOP.h"

/* 方法二：逐项插入 */
Polynomial Mult2(Polynomial P1, Polynomial P2){
    Polynomial Psum, Rear, temp, t1, t2;
    int c, e;

    if(!P1 || !P2) return NULL;

    Psum = (Polynomial)malloc(sizeof(struct PolyNode));
    Psum->Next = NULL;
    Rear = Psum;    
    t1 = P1; t2 = P2;
    while(t2){  /* 初始化， 用P1的第一项乘P2的每一项 */
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->Next;
    }
    Rear->Next = NULL;
    temp = Psum;
    Psum = Psum->Next;
    free(temp);

    t1 = t1->Next;
    while(t1){
        t2 = P2; Rear = Psum;
        while(t2){
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            while(Rear->Next && Rear->Next->expon > e){
                Rear = Rear->Next;
            }
            if(Rear->Next && Rear->Next->expon == e){
                if(Rear->Next->coef + c){   /* 判断是否为0，是则需要删除 */
                    Rear->Next->coef += c;
                }else{
                    temp = Rear->Next;
                    Rear->Next = temp->Next;
                    free(temp);
                }
                
            }else{  
                /* 不一定是最后项，是比前一项系数小的位置，所以不能用Attach(c, e, &Rear) */
                temp = (Polynomial)malloc(sizeof(struct PolyNode));
                temp->coef = c; temp->expon = e;
                temp->Next = Rear->Next;    //赋值temp的Next为空
                Rear->Next = temp;
                Rear = Rear->Next;
            }
            t2 = t2->Next;
        }
        t1 = t1->Next;
    }
    return Psum;
}



/* 方法一：将P1当前项(c1,e1)乘P2多项式，再加到结果多项式里 */
Polynomial Mult1(Polynomial P1, Polynomial P2){
    Polynomial P, Rear, Psum, temp, t1, t2;
    t1 = P1; t2 = P2;
    while(t1){
        t2 = P2;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Next = NULL;
        Rear = P;
        while(t2){
            Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
            t2 = t2->Next;
        }
        Rear->Next = NULL;
        temp = P;
        P = P->Next;    /* 令front指向结果多项式第一个非零项 */
        free(temp);
        Psum = PolyAdd(Psum, P);
        t1 = t1->Next;
    }
    return Psum;
}

#endif