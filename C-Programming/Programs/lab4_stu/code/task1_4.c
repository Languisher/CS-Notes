#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randnum(int *arr, int dim, int range)
{
    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
    for (int i = 0; i < dim; i ++)
    {
        *arr = rand() % range + 1;  //产生1-100的随机数
        arr++;
    }
}

void ivec_print_p1(int *x, int n) 
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *x++);
    }
    printf("\n");
}


void insertion_sort(int arr[], int len)
{
    int i,j,key;
    for (i=1;i<len;i++)
    {
        key = arr[i];
        j=i-1;
        while((j>=0) && (arr[j]>key)) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}



int main(){
    int dim = 10;
    int range = 8;
    clock_t begin, end; //! 计时
    int arr[dim];

    randnum(arr, dim, range);

    ivec_print_p1(arr, dim);

    // TODO

    begin = clock();

    insertion_sort(arr, dim);

    end = clock(); 

    ivec_print_p1(arr, dim);

    double cost = end - begin;
    printf("dim=%d:\t", dim);
    printf("time=%f\n",cost);

    return 0;
}