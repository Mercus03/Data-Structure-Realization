#include<iostream>
#include "PolyNode.h"
#include "AddOP.h"
#include "MultOP.h"

/*
设计函数分别求两个一元多项式的乘积与和
### 输入样例：
4 3 4 -5 2 6 1 -2 0
3 5 20 -7 4 3 1
### 输出样例：
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

using namespace std;
Polynomial ReadPoly();
void PrintPoly(Polynomial P);

int main(){
    Polynomial P1, P2, PM, PA;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PM = Mult1(P1, P2);
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
    while(P){
        printf("%d %d ",P->coef, P->expon);
        P = P->Next;
    }
    cout<<endl;
}



