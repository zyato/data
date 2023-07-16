#include<stdio.h>

int main()
{

    int i,j,ch;
    scanf("%d",&i);
    printf("i = %d\n",i);
    
    while((ch = getchar()) !='\n')
        continue;
       
    scanf("%d",&j);
    printf("j = %d",j);
    
    return 0;
}