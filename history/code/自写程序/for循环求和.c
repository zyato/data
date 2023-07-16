#include<stdio.h>

int main()
{
    int i,sum,j;
    sum = 0;
    scanf("%d" , &j);
    
    for(i = 1; i <= j; ++i)
        sum += i;
    printf("%d", sum);
    return 0;
}