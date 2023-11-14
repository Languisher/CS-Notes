
// 3.3 用函数指针变量作参数，求最大值、最小值和两数之和。

#include <stdio.h>

int max(int,int);
int min(int,int);
int add(int,int);
int process(int,int,int (*fun)(int,int));

int main()
{
  int a,b;
  printf("enter a and b:");  
  scanf("%d %d",&a,&b);

  // TODO

  int max_num, min_num, add_num;
  max_num = process(a, b, max);
  min_num = process(a, b, min);
  add_num = process(a, b, add);

  printf("%d", max_num);

  return 0;
}

int process(int x,int y,int (*fun)(int,int))
{ 
  int result;
  result=(*fun)(x,y);
  printf("%d\n",result);
  return 0;
}

int max(int x,int y)
{   
  printf("max=");
  return(x>y?x:y);
}

int min(int x,int y)
{ 
  printf("min=");
  return(x<y?x:y);
}

int add(int x,int y)
{  
  printf("sum=");  
  return(x+y);
}

