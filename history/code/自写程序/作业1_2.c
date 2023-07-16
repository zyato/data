//十进制转二进制
#include<stdio.h>

int main()
{
    int i=0, m, n;
    int * num=(int*)malloc(sizeof(int)*50);
    scanf("%d",&m);
    
    while(m != 0)
    {
        num[i] = m%2;
        m /= 2 ;
        ++i;
    }
    for(n=i-1; n>=0; --n)
        printf("%d", num[n]);
    return 0;
}