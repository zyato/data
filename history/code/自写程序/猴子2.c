#include<stdio.h>

int main()

{
    int i,j=1,s;
    for(i=1;i<10;++i)
    {s=(j+1)*2;
    j=s;}
    printf("%d",s);
    return 0;
}