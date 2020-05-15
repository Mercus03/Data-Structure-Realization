#ifndef OP_H
#define OP_H
#include "StructStack.h"
#include <stdio.h>

void Push(Stack PtrS, ElementType item){
    if(PtrS->Top == MAXSIZE -1 ){
        printf("堆栈满");
        return;
    }else{
        PtrS->Data[++(PtrS->Top)] = item;   /* PtrS->Top ++;  PtrS->Data[Ptrl->Top]=item; */
        return;
    }
}

ElementType Pop(Stack PtrS){
    if(PtrS->Top == -1){
        printf("堆栈空");
        return NULL;
    }else{
        return (PtrS->Data[(PtrS->Top)--]);
    }
}


#endif