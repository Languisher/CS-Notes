#include <stdio.h>

int test () {
    static int array[10] = {0, 1};
    static int test = 2;
    test += 1;
    return test;
}

int main () {
    int num = 0;
    while( num < 10 ) {
        num = test();
    }
    printf("%d", test());
}