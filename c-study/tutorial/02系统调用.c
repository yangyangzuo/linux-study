#include <stdlib.h>
#include <stdio.h>
int main(){
	// 系统调用函数,需要引入stdlib.h
    // 可以在c语言的代码中调用另外一个程序
    // system()的返回值,不同的平台返回只不一样
    // windows返回的是,调用的命令中的main函数的返回值,而linux中则不一定
    // 不同平台的c语言库函数只能保证调用语法一样,不能保证执行结果也一样(不同平台的c语言执行需要一定的移植工作)
    // posix标准:
    // 只要符合这个标准的函数,在不同的系统下执行的结果就可以一样
    // unix和linux很多库函数都支持posix,但是window支持的较差,所以unnix和linux代码移植代价小,windows代码和unix/linux之间移植代价大
    // 所以尽量使用符合posix标准的函数
    int result = system("ls -la");
    printf("result is :%d\n",result);
	return 0;
}

// 如果知道函数使用哪个头文件
// #man man 
// 1   Executable programs or shell commands
// 2   System calls (functions provided by the kernel)
// 3   Library calls (functions within program libraries)
// 4   Special files (usually found in /dev)
// 5   File formats and conventions eg /etc/passwd
// 6   Games
// 7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7)
// 8   System administration commands (usually only for root)
// 9   Kernel routines [Non standard]



// 如何查看库函数使用的对应系统头文件:
// #man 3 printf
// 如下打印结果可以看出来使用的时stdio.h头文件
// SYNOPSIS
// #include <stdio.h>
// int printf(const char *format, ...);
// int fprintf(FILE *stream, const char *format, ...);



// man 3 system
// 如下打印结果可以看出来使用的时stdlib.h头文件
// SYNOPSIS
// #include <stdlib.h>
// int system(const char *command);



// system()函数的返回值
// RETURN VALUE
// The return value of system() is one of the following:

// *  If command is NULL, then a nonzero value if a shell is available, or 0 if no shell is available.

// *  If a child process could not be created, or its status could not be retrieved, the return value is -1.

// *  If a shell could not be executed in the child process, then the return value is as though the child shell terminated by calling _exit(2) with the status 127.

// *  If all system calls succeed, then the return value is the termination status of the child shell used to execute command.  (The termination status of a shell is the termination status of the last command it executes.)

// In the last two cases, the return value is a "wait status" that can be examined using the macros described in waitpid(2).  (i.e., WIFEXITED(),  WEXITSTATUS(), and so on).

// system() does not affect the wait status of any other children.
