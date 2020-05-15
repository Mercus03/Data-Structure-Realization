#ifndef SEQOP_H
#define SEQOP_H
#include "StructNode.h"
#include <stdio.h>

List MakeEmpty(){
    List Ptrl;
    /*malloc—— memory allocation，动态内存分配，用于申请一块连续的指定大小的内存块区域以void*类型返回分配的内存区域地址，
    当无法知道内存具体位置的时候，想要绑定真正的内存空间，就需要用到动态的分配内存*/
    Ptrl = (List)malloc(sizeof(struct LNode));  
    Ptrl->Last = -1;
    return Ptrl;
}

int Find(ElementType X, List Ptrl){
    int i = 0;
    while(i <= Ptrl->Last && Ptrl->Data[i] != X)
        i++;
    if(i > Ptrl->Last){ /*如果没找到，返回-1*/
        return -1;
    } else{
        return i;   /*  返回存储位置 */
    }
}

void Insert(ElementType X, int i, List Ptrl){
    if(Ptrl->Last == MAXSIZE -1){   /*  表空间已满 */
        printf("表满");
        return;
    }
    if(i < 1 || i> Ptrl->Last +2){  /*  检查插入位置的合法性*/
        printf("位置不合法");
        return;
    }

    for( int j = Ptrl-> Last; j >= i; j--)
        Ptrl->Data[j+1] =  Ptrl->Data[j];
    Ptrl->Data[i] = X;
    Ptrl->Last ++;
    return;
}

void Delete(ElementType X, int i, List Ptrl){

    if(i < 1 || i > Ptrl->Last +1){  /*  检查删除位置的合法性*/
        printf("不存在第%d个元素", i);
        return;
    }
    for(int j=i ;j<=Ptrl->Last; j++)
        Ptrl->Data[j-1] = Ptrl->Data[j];
    Ptrl->Last--;
    return;
}

#endif