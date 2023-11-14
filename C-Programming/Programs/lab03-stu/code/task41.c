
#include <stdio.h>

char *strcpy( char *strDestination, const char *strSource){
  // TODO  
}

int main()
{
  char buff[8] = {0};
  char *p = "0123456789";
  strcpy(buff,p);
  printf("%s\n",buff);
  return 0;
}