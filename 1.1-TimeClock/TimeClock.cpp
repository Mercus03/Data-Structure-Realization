#include<stdio.h>
#include<time.h>
#include<math.h>
#include"MyFunction.h"

using namespace std;

double duration;
clock_t start, stop;
#define MAXN 10     /* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7    /* 循环次数 */
typedef double(*PFUN)(int n, double a[], double x); /* 函数指针 */

double CountDuration(PFUN pfun, double a[]){    /* 函数指针作为函数的参数 */
    start = clock();
    for(int i=0; i<MAXK; i++){
        pfun(MAXN-1, a, 1.1);
    }
    stop = clock();
    double duration = ((double)(stop-start))/CLK_TCK/MAXK;
    printf("ticks = %f\n", (double)(stop - start));
    return duration;
}

int main()
{
    int i;
    double a[MAXN];
    for (i=0; i<MAXN; i++){ a[i] = (double)i; }

    PFUN pfun1 = f1;    /* 将函数指针指向f1,f2 */
    printf("duration1 = %6.2e\n", CountDuration(pfun1, a));
    PFUN pfun2 = f2;
    printf("duration2 = %6.2e\n", CountDuration(pfun2, a));

    // start = clock();
    // f1(MAXN-1, a, 1.1);
    // stop = clock();
    // duration = ((double)(stop - start));
    // printf("ticks1 = %f\n", (double)(stop - start));
    // printf("duration1 = %6.2e\n", duration);

    // start = clock();
    // f2(MAXN-1, a, 1.1);
    // stop = clock();
    // duration = ((double)(stop - start));
    // printf("ticks1 = %f\n", (double)(stop - start));
    // printf("duration1 = %6.2e\n", duration);
}