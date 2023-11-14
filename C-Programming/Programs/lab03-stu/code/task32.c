
// 3.2	求a和b中的最大者。
//(2)通过指针变量访问函数：

#include <stdio.h>

int max(int , int);  

int main()
{ 
  
  int a,b,c;
  scanf("%d %d",&a,&b);

  int (*p)(int , int);

  p = max;
  c = (*p)(a,b);
  // TODO
  printf("a=%d,b=%d,max=%d\n",a,b,c);
  return 0;
}

int max(int x,int y)
{ 
  int max_number;
  if(x>y)  
    max_number=x;
  else  
    max_number=y;

  return max_number;
}
