#ifndef QUEUE_H
#define QUEUE_H
#define ElementType char
#define MAXSIZE 100

/* 循环队列，仅使用n-1个空间判满/空 */
typedef struct QNode *Queue;
struct QNode{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
};


/* 链式队列 */
struct Node{    /* 节点结构 */
    ElementType Data;
    struct Node *Next;
};

struct LQNode{  /* 链式队列结构 */
    struct Node *front;
    struct Node *rear;
};
typedef struct LQNode *LQueue;
LQueue PtrQ;

#endif