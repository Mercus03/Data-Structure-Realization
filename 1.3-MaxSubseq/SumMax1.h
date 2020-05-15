#ifndef SumMax1_H
#define SumMax1_H

int MaxSubseqSum1(int A[], int N){
    int ThisSum, MaxSum = 0;
    int i,j;
    for(i = 0; i<N; i++){
        ThisSum += A[j];
        if( ThisSum > MaxSum){
            MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

#endif