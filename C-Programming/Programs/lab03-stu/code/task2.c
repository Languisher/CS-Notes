/*
    指针数组
    char *a[]：表示a是数组，数组中的元素是指针，指向char类型
    数组里面所有的元素是连续的内存存放的 
    数组名是数组第一个字节的内存地址，并且数组名a也表示指针
    注意：a并不表示a地址存储的内容, 而是a地址本身
    注意到：因为a的元素是char指针, 所需要的空间为8字节(64位内存地址)
    那么：
    a+1：表示a的第二个元素的内存地址, 所以是加 8 字节
    *(a+1)：则表示a这个数组的第二个元素的内容 (是个char 类型的指针，本例表示为GNUC字符串的地址)。
    *(*(a+1))：则表示a这个数组的第二个元素的内容(char指针)所指向的内容(G字符).
    char * a[3]：表示限定这个数组最多可存放3个元素(char指针), 也就是说这个数组占用3*8 = 24字节。
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    char *a[]={"Hello","GNUC","world"};
    //! 分析：
    //! 首先从 a 处开始, 先与 [] 结合，因为其优先级比 * 高
    //! 所以 a 是一个数组, 然后再与 * 结合, 说明数组里的元素是指针类型
    //! 然后再与 char 结合, 说明指针所指向的内容的类型是字符型的 


    //! for teacher 
    //! analysis:
    printf("%c\n",*(a[0]+1));       //! e
    printf("%s\n",*(a+1));          //! GNUC
    printf("%c\n",*(a+1)[0]);       //! G

    printf("a[0]:       %p\n",(a[0]));          //! 
    printf("a[0]+1:     %p\n",(a[0]+1));        //! 
    printf("a[1]:       %p\n",(a[1]));          //!    hello,GNUC 从h到G跳了6步，考虑'\0'
    printf("(a+1)[0]:   %p\n",(a+1)[0]);        //! 
    printf("a:          %p\n",(a));             //! 
    printf("a+1:        %p\n",(a+1));           //! 
    
    //! a[0] 是数组里的元素，是指针类型，char ＊，指向 H 所在地址 
    //! *a[0] 则代表 H
    //! a[0] + 1 指向 e 所在地址 
    //! *(a[0] + 1) 则代表 e
    //! 注意  %c  %s 的区别
    //! output "Hello"
    //! output "ello"
    //! output "d"

    // TODO
    printf("%s\n", *a);              //! Hello
    printf("%s\n", a[0]);            //! Hello

    printf("%s\n", *(a) + 1);            //! ello
    printf("%s\n", a[0] + 1);          //! ello

    // remind:
    printf("%s\n", *(a+1));          //! GNUC
    printf("%s\n", a[1]);            //! GNUC 
    printf("%c\n", a[1][0]);         //! G


    printf("%c\n", *(a[2]+4));    //! d 
    printf("%c\n", a[2][4]);        //! d

    //! char b[][5]={"Hello","GNUC","world"};
    //! printf("%c\n", b[1][0]); //! d

    //! summarize: 
    //! Table Subscript expressions and equivalent pointer expressions for a vector
    //! Description                         Using array subscript   Using pointer
    //! Value of the first array elemen:    a[0]                    *a
    //! Address of the first array element  &a[0]                   a
    //! Value of the ith array element      a[i]                    *(a+i)
    //! Address of the ith array element    &a[i]                   a+i

    

    
}