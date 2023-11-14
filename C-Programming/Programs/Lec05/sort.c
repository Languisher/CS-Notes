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

void merge_sort_recursive(int arr[], int sorted_arr[], int start, int end) 
{
    if( start >= end ) {
        return ;
    }

    int len = end - start; 
    int mid = start + len / 2;

    int left_start = start; int left_end = mid;
    int right_start = mid + 1; int right_end = end;

    merge_sort_recursive(arr, sorted_arr, left_start, left_end);
    merge_sort_recursive(arr, sorted_arr, right_start, right_end);

    int sorted_arr_pos = start; 

    while (left_start <= left_end && right_start <= right_end) {
        sorted_arr[sorted_arr_pos++] = arr[left_start] < arr[right_start] ? 
                                       arr[left_start++] : arr[right_start++];                                 
    }

    while (left_start <= left_end) {
        sorted_arr[sorted_arr_pos++] = arr[left_start++];
    }

    while (right_start <= right_end) {
        sorted_arr[sorted_arr_pos++] = arr[right_start++];
    }

    for (sorted_arr_pos = start; sorted_arr_pos <= end; sorted_arr_pos++) {
        arr[sorted_arr_pos] = sorted_arr[sorted_arr_pos];
    }
}

void merge_sort(int arr[], int len) 
{
    int sorted_arr[len];
    merge_sort_recursive(arr, sorted_arr, 0, len - 1);
}

void main_process(double * avg_time_arr, double * max_time_arr, int dim) {
    int origtable[10000];                  //待排数组
    int NTable = dim;                    //元素个数
    double timeexe[100];                   //每次随机试验的时间
    int NTest = 100;                       //试验次数
    for(int k=0; k<NTest; k++)
    {
        randnum(origtable,NTable,10000);   //生成随机数数组
        
        // ivec_print_p1(origtable,NTable);

        clock_t begin, end;
        begin=clock();
        merge_sort(origtable,NTable);
        check(origtable, NTable);
        end=clock();
        
        // ivec_print_p1(origtable,NTable);
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
}
int main()
{
    double avg_time_arr[5], max_time_arr[5];
    int DIM_LIST[5] = [10, 100, 1000, 10000, 100000];

    for(int index = 0; index < 5; index++) {
        int dim = DIM_LIST[index];
        main_process(avg_time_arr, max_time_arr, dim);
    }

    return 0;  
}