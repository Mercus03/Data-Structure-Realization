#ifndef LIST_H
#define LIST_H
#define MAXSIZE 100
#define ElementType char

 #include <stdlib.h>
/*
typedef是定义一个类型,定义的类型叫做List(注意他现在是一个类型,和int char char*一样)
这是一个什么类型那? 这是一个结构体指针类型,这种类型的变量都指向LNode结构;
List PtrL;就是根据结构体指针类型,定义一个结构体指针变量
List就代表 struct LNode 类型
*/

typedef struct LNode *List; //将LNode* 用List代替， List代表指向struct地址的指针
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L; // L: 结构体
List Ptrl;  //Ptrl 就相当于 LNode* ptrl: 结构体指针变量

//访问下标为i的元素： L.Data[i] 或 Ptrl->Data[i]
//线性表的长度： L.Last+1 或 Ptrl->Last+1


/*  链表  */
typedef struct LinkedNode *LList; //将LinkedNode* 用LList代替
struct LinkedNode{
    /*   数据域 + 后继指针域   */
    ElementType Data;
    LList Next;
};
struct LinkedNode LN; // LN: 结构体
LList LPtrl;

#endif
