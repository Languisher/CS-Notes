#include <stdio.h>

#define MAX_STRING 10

// 声明自定义的字符串拷贝函数
char * strcpy(char * strDestination, const char * strSource);
char * ourstrncpy(char * strDestination, const char * strSource, int strDestinationMaximumLength);

int main() {
    char loc1[MAX_STRING], loc2[MAX_STRING];
    char *ptrString1 = "shortstr";
    char *ptrString2 = "longstr+longstr";

    printf("We set the longest string length is : %d\n", MAX_STRING);
    printf("***************************************\n");

    printf("First str: shortstr\n");

    // 使用标准的 strcpy 函数复制字符串
    strcpy(loc1, ptrString1);

    // 使用自定义的 ourstrncpy 函数复制字符串，限制长度为 MAX_STRING
    ourstrncpy(loc2, ptrString1, MAX_STRING);

    printf("With the function strcpy, we obtain loc1: %s\n", loc1);
    printf("With the function strncpy, we obtain loc2: %s\n", loc2);

    printf("***************************************\n");
    printf("Second str: longstr+longstr\n");

    // 使用标准的 strcpy 函数复制较长的字符串
    strcpy(loc1, ptrString2);

    // 使用自定义的 ourstrncpy 函数复制较长的字符串，限制长度为 MAX_STRING
    ourstrncpy(loc2, ptrString2, MAX_STRING);

    printf("With the function strcpy, we obtain loc1: %s\n", loc1);
    printf("With the function strncpy, we obtain loc2: %s\n", loc2);

    // 将 loc1 中，以及其随后的空间的字符初始化为零
    char * ptrStringTest = loc1; 
    for(int count=0; count<= MAX_STRING * 2; count++) {
        *ptrStringTest++ = 0; 
    }

    printf("***************************************\n");

    // 使用标准的 strcpy 函数复制字符串，但在超出 MAX_STRING 长度后的字符未定义
    strcpy(loc1, ptrString2);
    printf("With initialization of the following (undefined) spaces after loc1, using the function strcpy, we obtain loc1: %s\n", loc1);

    return 0;
}

// 自定义的字符串拷贝函数，复制一个字符串到另一个字符串
char * strcpy(char * strDestination, const char * strSource) {
    if (strDestination == NULL || strSource == NULL) {
        return NULL;
    }
    char *ptrDestination = strDestination;

    // 逐个字符复制源字符串到目标字符串，直到遇到字符串结束符 '\0'
    while ((*ptrDestination++ = *strSource++) != '\0') {
        ;
    }
    return strDestination;
}

// 自定义的字符串拷贝函数，复制一个字符串到另一个字符串，并限制最大长度
char * ourstrncpy(char * strDestination, const char * strSource, int strDestinationMaximumLength) {
    if (strDestination == NULL || strSource == NULL) {
        return NULL;
    }
    char *ptrDestination = strDestination;

    // 逐个字符复制源字符串到目标字符串，直到遇到字符串结束符 '\0' 或达到最大长度
    for( int count = 0; 
         (*ptrDestination++ = *strSource++) != '\0'; 
         count++) {
            if (count >= strDestinationMaximumLength) {
                *--ptrDestination = '\0';
                break;
            }
         }

    return strDestination;
}
