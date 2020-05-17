#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

struct PolyNode{
    int coef;   //系数
    int expon;  //指数
    struct PolyNode *Next;  //指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

#endif