#include<stdio.h>

int main()
{
    int i;
    
    i = (3>2?5:4);   /* 等价于 if(3>2)
                                  i=5;
                              else
                                  i=4;
                     */
    printf("i= %d",i);
    return 0;
}