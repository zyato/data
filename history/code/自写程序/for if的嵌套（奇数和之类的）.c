#include<stdio.h>

int main()
{
    int i,sum = 0;
    
    for(i = 1; i <= 100; ++i)
    {
        if(i%2 !=  0)
            sum += i;
   
    }
    sum += 2550,
    printf("sum = %d",sum);
    
    return 0;
}