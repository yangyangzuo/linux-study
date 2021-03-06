#include <stdio.h>
int main(){
 
    printf("----------1--------\n");
    unsigned int a = 1;
    // man 3 printf
    // 输出整型%d,8进制整型%o,16进制整型%x,16进制整型(ABCDEF用大写)%X,当做10进制无符号整数输出%u
    printf("%d\n",a);//1


    int b = -2;
    // 把-2当做一个无符号整数输出
    // 因为sizeof(b)==4,int类型在当前系统中占用4个字节
    // 原码
    // 10000000 00000000 00000000 00000010
    // 反码
    // 11111111 11111111 11111111 11111101
    // 补码(内存中存储的内容)
    // 11111111 11111111 11111111 11111110

     

    // 转换为无符号整数
    // ff ff ff fe = 15*16^7 + 15*16^6 + 15*16^5 + 15*16^4 + 15*16^3 + 15*16^2 + 15*16 + 14 = 4294967294
    // js中15*Math.pow(16,7)+15*Math.pow(16,6)+15*Math.pow(16,5)+15*Math.pow(16,4)+15*Math.pow(16,3)+15*Math.pow(16,2)+15*16+14=4294967294

    printf("%d\n",b);//-2
    printf("%x\n",b);//fffffffe,把一个数值,按照16进制的形式打印出来,能真实的反映出来内存中数据的存放形式


 
        



    
    printf("----------2--------\n");
    // 溢出测试
    // 有符号整型当前系统占用4个字节,最大值
    // 01111111 11111111 11111111 11111111
    // 加1后(内存中变成了)
    // 10000000 00000000 00000000 00000000
    
    int c = 0x7fffffff;// 16进制形式,对应着当前内存中的二进制存放形式
    // 内存中:01111111 11111111 11111111 11111111
    // 内存中的值是一个补码,但是根据这个存放形式可以看出来是一个正数,所以,正数的原码和补码相同
    // 最终当成一个有符号正数打印(%d),最终的有符号正数值是01111111 11111111 11111111 11111111
    // 即:2^31-1=2147483647
    printf("%d\n",c);//2147483647
    c = c + 1;
    // 内存中:01111111 11111111 11111111 11111111
    // +1
    // 内存中:10000000 00000000 00000000 00000000
    printf("%x\n",c);//80000000
    // 内存中:10000000 00000000 00000000 00000000
    // 内存中的值是一个补码,但是根据这个存放形式可以看出来是一个负数,所以,如果要显示成一个有符号的整数,需要转换为原码
    // 补码:10000000 00000000 00000000 00000000
    // 反码:11111111 11111111 11111111 11111111
    // 原码:10000000 00000000 00000000 00000000
    // 即:除去符号位,全为0,表示一个特殊的值:-2^31=-2147483648
    printf("%d\n",c);//-2147483648
    // 从结果可以发现,一个整数+1后,变成了一个负数


 

    printf("----------3--------\n");
    int d = 0x7fffffff;// 16进制形式,对应着当前内存中的二进制存放形式
    // 内存中:01111111 11111111 11111111 11111111
    // 内存中的值是一个补码,但是根据这个存放形式可以看出来是一个正数,所以,正数的原码和补码相同
    // 最终当成一个有符号正数打印(%d),最终的有符号正数值是01111111 11111111 11111111 11111111
    // 即:2^31-1=2147483647
    printf("%d\n",d);//2147483647
    d = d + 2;
    // 内存中:01111111 11111111 11111111 11111111
    // +2
    // 内存中:10000000 00000000 00000000 00000001
    printf("%x\n",d);//80000001
    // 内存中:10000000 00000000 00000000 00000001
    // 内存中的值是一个补码,但是根据这个存放形式可以看出来是一个负数,所以,如果要显示成一个有符号的整数,需要转换为原码
    // 补码:10000000 00000000 00000000 00000001
    // 反码:10000000 00000000 00000000 00000000
    // 原码:11111111 11111111 11111111 11111111
    // 即:-(2^31-1)=-2147483647
    printf("%d\n",d);//-2147483647
    

    // 有符号数字的原码表示的值的范围:
    // 如果是8位
    // 第一位是符号位. 因为第一位是符号位, 所以8位二进制数的取值范围就是:
    // [1000 0000 , 0111 1111]
    // 即[-128 , 127]
    // 即:对于原码来说,最高位表示符号位,不属于数值范围
    // 所以原码    11111111 11111111 11111111 11111111
    // 表示的值    -1111111 11111111 11111111 11111111
    // 即:-(2^31-1)=-2147483647
    // 但是对于全为0的负数原码,表示一个特殊的值:
    // 10000000 00000000 00000000 00000000
    // -0000000 00000000 00000000 00000000
    // 即:-2147483648


    return 0;
} 