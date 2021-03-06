#include <stdio.h>
int main(){
	printf("hello world");
	return 0;
}
/*
预编译指令:
    #include,包含头文件
    例如:
        使用printf函数，需要引入#include <stdio.h>头文件
    
    
    如果不使用可以不包含,例如：
    //#include <stdio.h>
    int main(){
    //	printf("hello world\n");
        return 0;//默认情况下约定:return 0,表示成功,return -1表示失败,当然return 其他的数字也是可以的,但是没有意义
    }


    stdio.h这个文件在系统目录下
    #sudo find / -name stdio.h
    /usr/include/stdio.h
    /usr/include/c++/8/tr1/stdio.h
    /usr/include/x86_64-linux-gnu/bits/stdio.h
    find: ‘/run/user/1000/doc’: Permission denied
    find: ‘/run/user/1000/gvfs’: Permission denied

    如果文件在系统目录下需要使用#include <文件名>
    如果文件在当前目录下需要使用#include "文件名"



    main函数的返回类型可以是void(下面的写法,不符合c++语法,如果把文件改成.cpp,则编译会报错,所以最好写成上面的返回类型为int)
    #include <stdio.h>
    void main(){
        printf("hello world");
    }
    或者
    #include <stdio.h>
    void main(){
        printf("hello world");
        return;
    }
*/