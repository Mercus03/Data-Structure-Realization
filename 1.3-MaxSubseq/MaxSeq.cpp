#include<iostream>

#include"DivideAndConquer.h"
#include"SumMax1.h"
#include"ProcessOnline.h"
using namespace std;
#define MAXN 100

void InputParam(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int k=0; k<n; k++)
        cin>>a[k];
    int b = MaxSubseqSum3(a, n);
    printf("MaxSubseq = %d\n", MaxSubseqSum3(a, n));
}

int main()
{
    //InputParam();
    int i;
    int a[MAXN];
    for (i=0; i<MAXN; i++) 
        a[i] = rand() % 61 - 40; 
    printf("MaxSubseq = %d\n", MaxSubseqSum3(a, MAXN));
}