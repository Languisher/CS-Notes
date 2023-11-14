#include <stdio.h>
#include <stdlib.h>

void ivec_print_p1(int *x, int n) 
{
    int i = 0;
    // TODO
    while (i++ < n) {
        printf("%d ", *x++);
    }
    printf("\n");
}


int main(){
    int arr[5] = {1,3,5,7,8};
    ivec_print_p1(arr, 5);
    return 0;
}