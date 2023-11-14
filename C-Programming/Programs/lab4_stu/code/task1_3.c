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
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}
void selection_sort(int arr[], int len)
{
    int i,j;

    for (i = 0 ; i <= len - 1 ; i++)
    {
        int min_index = i;
        for(int j = i; j <= len - 1; j++) {

            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        int tmp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = tmp;
        // todo
    }
}
int main(){
    int dim = 10;
    int range = 8;
    int arr[dim];
    randnum(arr, dim, range);
    ivec_print_p1(arr, dim);
    selection_sort(arr, dim);
    ivec_print_p1(arr, dim);

    return 0;
}