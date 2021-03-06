#include <stdio.h>
int main(){

    // 原码
    // 反码
    // 补码,负数在内存中是以补码的形式存放的



    return 0;
}
/*
一. 机器数
    一个数在计算机中的二进制表示形式,  叫做这个数的机器数。
    机器数是带符号的，在计算机用一个数的最高位存放符号, 正数为0, 负数为1.
    例：
    0000 0001 = +000 0001 = +1，
    1000 0001 = –000 0001 = –1





二. 原码, 反码, 补码的基础概念和计算方法.
    对于一个数, 计算机要使用一定的编码方式进行存储. 
    原码, 反码, 补码是机器存储一个具体数字的编码方式.

    1. 原码
    原码就是符号位加上真值的绝对值, 即用第一位表示符号, 其余位表示值. 比如如果是8位二进制:

    [+1]原 = 0000 0001

    [-1]原 = 1000 0001
 
    原码是人脑最容易理解和计算的表示方式.

    2. 反码
    反码的表示方法是:

    正数的反码是其本身

    负数的反码是在其原码的基础上, 符号位不变，其余各个位取反.

    [+1] = [00000001]原 = [00000001]反

    [-1] = [10000001]原 = [11111110]反

    可见如果一个反码表示的是负数, 人脑无法直观的看出来它的数值. 通常要将其转换成原码再计算.

    3. 补码
    补码的表示方法是:

    正数的补码就是其本身

    负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)

    [+1] = [00000001]原 = [00000001]反 = [00000001]补

    [-1] = [10000001]原 = [11111110]反 = [11111111]补

    对于负数, 补码表示方式也是人脑无法直观看出其数值的. 通常也需要转换成原码在计算其数值.

 
    负数补码的另一种表示方法:
    该数的绝对值的二进制形式,按位取反,再加1
    [-1] = [10000001]原 => [00000001]绝对值的二进制形式 => [11111110]按位取反 + 1 = [11111111]


三. 为何要使用原码, 反码和补码
    在开始深入学习前, 我的学习建议是先"死记硬背"上面的原码, 反码和补码的表示方式以及计算方法.

    现在我们知道了计算机可以有三种编码方式表示一个数. 对于正数因为三种编码方式的结果都相同:

    [+1] = [00000001]原 = [00000001]反 = [00000001]补
    [-1] = [10000001]原 = [11111110]反 = [11111111]补

    需求:
    1.人们想让符号位也参与运算,而不用计算数值的时候,先判断数值的符号
    2.设计简单,方便电路设计,让计算机中只有加法没有减法


    +7的原码,反码,补码 = 00000111
    7-6 = 7 + (-6) = 00000111(原) + 10000110(原) = 10001101(相加后的原码) =>转换为原码,这个只本身就是原码,不用转换,10001101 = -13(错误)
    7-6 = 7 + (-6) = 00000111(反) + 11111001(反) = 00000000(相加后的反码) =>转换为原码,11111111 = -128(错误)
                    +11111001(反)
                    100000000(反)最高位舍弃 = 00000000

    数值在内存中以补码形式存放,上面计算方式错误
    7-6 = 7 + (-6) = 00000111(补) + 11111010(补) = 00000001(相加后的补码) =>转换为原码,00000001,正数的原码和反码相等 = 1(正确)
                    +11111010(补)
                    100000001(补)最高位舍弃 = 00000001


    +6的原码,反码,补码 = 00000110
    -7+6 = (-7) + 6 = 10000111(原) + 00000110(原) = 10001001(相加后的原码) =>转换为原码,这个只本身就是原码,不用转换,10001001 = -9(错误)
    -7+6 = (-7) + 6 = 11111000(反) + 00000110(反) = 11111110(相加后的反码) =>转换为原码,10000001 = -1(正确)
                     +00000110(反)
                      11111110(反)      

    数值在内存中以补码形式存放,上面计算方式错误
    -7+6 = (-7) + 6 = 11111001(补) + 00000110(补) = 11111111(相加后的补码) =>转换为原码,10000001 = -1(正确)
                     +00000110(补)
                      11111001(补)                    


    从上面可以看出来,对于减法的运算,如果转成反码进行计算,值可能正确,但是转换成补码,却可以保证完全的正确性

    所以在计算机中,负数是按照补码的方式进行存储的

    使用补码计算,可以直接对负数进行加法运算

*/