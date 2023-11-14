/*
    类型是分配内存块大小的别名，即类型（int,double,char）的作用就是分配相对应大小的内存
    并给程序员一个名字（int,double,char）方便操作
    指针也是一种数据类型，定义时可以对其赋值（可赋任意地址值，但习惯赋值为NULL，方便操作管理）
*/

//! 在C语言中, sizeof() 是一个判断数据类型或者表达式长度的运算符。
//! sizeof并不是函数，而是一种编译指令，对sizeof的求值发生在编译器
//! 查看 int, double, char 型指针的长度


#include <stdio.h>
#include <string.h>
int main()
{
    //! section 1
    //! for teacher 
    int a1 = 1;
    int *p1 = &a1;
    int b1 = sizeof(p1);
    printf("%d\n",b1); //! 8个字节
    
    //! section 2
    //! for student
    double a2 = 1;
    double *p2 = &a2;
    int b2 = sizeof(p2);
    printf("%d\n",b2); //! 8个字节

    //! section 3
    //! for student
    char a3 = '1';
    char *p3 = &a3;
    int b3 = sizeof(p3);
    printf("%d\n",b3); //! 8个字节

    //! conclusion 
    //! int, double, char 型指针的长度均为8个字节，即机器为单个指针分配8个字节内存
}