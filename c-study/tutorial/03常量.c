#include <stdio.h>

// 宏常量,常量名一般用大写字母,而且结尾没有分号
// 宏定义最大的好处是“方便程序的修改”。使用宏定义可以用宏代替一个在程序中经常使用的常量
// 这样，当需要改变这个常量的值时，就不需要对整个程序一个一个进行修改，只需修改宏定义中的常量即可。宏定义的优点就是方便和易于维护
#define CONST1  100

int main(){
    // 定义宏常量
    #define CONST2 30

    // 使用const定义普通常量
    const int const3 = 200;

    // 常量不能修改
    // CONST1 = 1;//报错
    // CONST2 = 2;//报错
    // const3 = 3;//报错

    printf("%d\n",CONST1);//100
    printf("%d\n",CONST2);//30
    printf("%d\n",const3);//200

    return 0;
}