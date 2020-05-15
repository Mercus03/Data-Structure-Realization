#include <iostream>
using namespace std;

void t1();  /* Function prototype */

int main(){
    t1();
    t1();

    return 0;
}

void t1(){
    static int x = 1;   /* 调用后x值保留在该函数开辟的内存中 */
    int y = 1;
    x++;
    y++;
    printf("x is %d\n",x);  /* "\n"换行 */
    printf("y is %d\n",y);
}
