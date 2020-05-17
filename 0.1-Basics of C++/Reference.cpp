#include <iostream>
using namespace std;


/* java中所有的基本数据类型和引用类型 都是值传递！！

    函数change(p){ p = new P("pp"); ... } 
    无法改变p的内容，因为是复制了对象p
    对于基本类型来说“=”赋值操作是直接改变内存地址上的值，
    对于引用类型来说“=”赋值其实是改变引用变量所指向的内存地址。

    class Person{ 
        String name = "java";
        public void setName(String name){ this.name = name; }}
    void changeName (Person p1){ p1.setName("javascript" );
    Person p = new Person();
    changeName(p);

    首先在堆内存中创建了一个Person对象,然后在栈内存中创建了一个引用类型的变量p,
    p指向堆内存中的Person对象,即p的值为Person对象在内存中分配空间的首地址值.
    调用changeName()函数时,栈中再次创建一个引用类型的变量p1,然后将p中的值拷贝给p1,即p1也指向Person对象. 
    调用完成后,p1指向的Person对象的name属性被改变为javascript.
    由于p和p1指向同一个Person对象,因此p指向的Person对象的name值也变为javascript.
    这看起来类似于引用传递,但是这仍然是值传递,p1接受的值是p的值的拷贝,函数调用完成后,p的值完全没有改变,仍然是指向之前创建的Person对象,这就是值传递.
    整个过程中改变的是Person对象的属性name,由于p和p1都指向这个Person对象,因此p和p1产生了相同的变化,使得看起来像是进行了引用传递.
*/

/* 引用传递 */
void increment(int &n){ /* &表示变量的一个别名，共享内存*/
    n++;
    cout<< "Inside the function: n="<< n <<endl;
}

void swap(int &n1, int &n2){    /* 简单的n1,n2只能进行值传递，无法交换 */
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main(){
    int x = 1;
    increment(x);
    cout<<"After the call: x=" <<x << endl;

    int num1 = 1;
    int num2 = 2;
    swap(num1, num2);
    cout<< "num1="<< num1 << "  num2="<<num2<<endl; 
}
