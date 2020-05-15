#ifndef CIRCLE_H
#define CIRCLE_H

int MaxSubseqSum3(int List[], int N){

    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i = 0; i<N; i++){
        ThisSum += List[i]; //向右累加
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;   // 发现更大和则更新当前结果
        }else if(ThisSum < 0){  // 如果当前子列和为负数
            ThisSum = 0;    // 则不可能使后面部分和增大，抛弃之
        }
    }
    return MaxSum;
}

#endif