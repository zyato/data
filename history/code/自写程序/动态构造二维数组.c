#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int weishu,i,j;
	printf("¾ØÕóÎ¬Êı");
	scanf_s("%d", &weishu);
	int ** hang = (int **)malloc(sizeof(int*)*weishu);
	for (i = 0; i < weishu; ++i)
	{
		hang[i] = (int*)malloc(sizeof(int)*weishu);
	}
	for (i = 0; i < weishu; ++i)
	{
		for (j = 0; j < weishu; ++j)
		{
			scanf_s("%d", &hang[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < weishu; ++i)
	{
		for (j = 0; j < weishu; ++j)
		{
			printf("%d",hang[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}