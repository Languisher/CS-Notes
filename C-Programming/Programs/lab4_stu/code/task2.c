#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check(int* arr, int len){
    for (int i = 0; i < len -1; ++i){
        if (arr[i] > arr[i+1]){
            printf("Arr is not sorted!");
            return;
        }
    }
}

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


void swap(int *a,int *b) //交换两个变量
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

int main()
{
    int origtable[10000];                  //待排数组
    int NTable = 10000;                    //元素个数
    double timeexe[100];                   //每次随机试验的时间
    int NTest = 100;                       //试验次数
    for(int k=0; k<NTest; k++)
    {
        randnum(origtable,NTable,10000);   //生成随机数数组
        //ivec_print_p1(origtable,NTable);
        clock_t begin, end;
        begin=clock();
        selection_sort(origtable,NTable);
        check(origtable, NTable);
        end=clock();
        //ivec_print_p1(origtable,NTable);
        timeexe[k] = (double)(end-begin);
    }
    
    double average_time = 0;
    double min_time=timeexe[0], max_time=timeexe[0];

    for(int k=0; k<NTest; k++)
    {
        average_time+=timeexe[k];
        if(timeexe[k]>max_time)
            max_time = timeexe[k];
        if(timeexe[k]<min_time)
            min_time = timeexe[k];
    }
    average_time/=NTest;
    printf("Best: %lf\n",min_time);
    printf("Average: %lf\n",average_time);
    printf("Worst: %lf\n",max_time);
    return 0;  
}