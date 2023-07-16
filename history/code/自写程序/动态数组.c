#include<stdio.h>
#include<malloc.h>

int main()
{   
    int geshu,i;
    printf("请输入元素个数：");
    scanf("%d", &geshu);
    int * pArr = (int *)malloc(geshu * sizeof(int));
    printf("请输入数组各个值：");
    for (i = 0; i < geshu;  ++i)
      scanf("%d", &pArr[i]);
    for (i = 0; i < geshu; ++i)
      printf("%d\n", pArr[i]);
    return 0;
}