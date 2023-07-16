//判断输入的数是否既是5的倍数又是7的倍数
#include<stdio.h>

int main()
{
    int i;
    scanf("%d", &i);
    if(i%5 || i%7)
        printf("no\n");
    else
        printf("yes\n");
    return 0;
}