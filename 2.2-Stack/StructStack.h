#ifndef STACK_H
#define STACK_H
#define MAXSIZE 100
#define ElementType char



typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top;
};

typedef struct LSNode *LStack;
struct LSNode{
    ElementType Data;
    struct LSNode *Next; 
};

#endif