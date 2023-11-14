#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define dim      //生成多大的数组
// #define range    //数组的元素大小从1到range
//! 产生长度为dim，数值在［1-range］区间的随机数
void randnum(int *arr, int dim, int range)
{
    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样

    for (int index = 0; index < dim; index++) {
        arr[index] = (rand() % range) + 1;
    }
}

int main(){
    int dim = 10;
    int range = 5;
    int arr[dim];
    randnum(arr, dim, range);

    for (int i = 0; i < dim; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}