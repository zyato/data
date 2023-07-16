#include<stdio.h>

int main()
{    
    int num,i;
  for(num=2;num<=100;++num)
   {
    for(i=2;i<=num;++i)
    {
        if(0==num%i) break;
    }
    if(i==num)
    printf("%d\n",num);
  }
    return 0;
}