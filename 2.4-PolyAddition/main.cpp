#include<iostream>
#include "PolyNode.h"
#include "AddOP.h"

using namespace std;
Polynomial ReadPoly();
Polynomial Mult(Polynomial P1, Polynomial P2){};
void PrintPoly(Polynomial P);

int main(){
    Polynomial P1, P2, PM, PA;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PM = Mult(P1, P2);
    PrintPoly(PM);
    PA = PolyAdd(P1, P2);
    PrintPoly(PA);

    return 0;
}

Polynomial ReadPoly(){
    int N, c, e;
    PolyNode *front, *rear, *temp;
    scanf("%d", &N);    /* 读入项数 */

    rear = (PolyNode *)malloc(sizeof(struct PolyNode));
    front = rear;
    while(N--){
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);
    }
    rear->Next = NULL;
    temp = front;
    front = front->Next;
    free(temp);
    return front;
}

void PrintPoly(Polynomial P){
    int N, c, e;
    
}

Polynomial Mult1part(Polynomial P1, Polynomial P2){
    /* 将P1当前项(ci, ei)乘P2多项式，再加到结果多项式中 */
    Polynomial P, Rear, PSum;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->Next = NULL;
    Rear = P;
    while(P2){
        Attach(P1->coef * P2->coef, P1->expon + P2->expon, &Rear);
        P2 = P2->Next;
    }
    return 
    
}