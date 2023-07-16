#include<stdio.h>
#include<stdlib.h>

void InPut(int *, int);//输入
void OutPut(int *, int);//输出
void Sort(int *, int);//排序

int main(void)
{
	int lon;
	printf("请输入数值的个数：");
	scanf_s("%d", &lon);
	int * a = (int *)malloc(sizeof(int)*lon);

	InPut(a, lon);
	Sort(a, lon);
	printf("排序结果是：\n");
	OutPut(a, lon);

	system("pause");
	return 0;
}
void InPut(int * p, int lon)
{
	int i;
	printf("请输入%d个数：", lon);
	for (i = 0; i < lon; ++i)
	{
		scanf_s("%d", &p[i]);
	}
	printf("\n");
}

void OutPut(int * p, int lon)
{
	int i;
	for (i = 0; i < lon; ++i)
	{
		printf("%d   ", p[i]);
	}
	printf("\n");
}

void Sort(int * p, int lon)
{
	int i, j, t;
	for (i = 0; i < lon - 1; ++i)
	{
		for (j = 0; j < lon - i - 1; ++j)
		{
			if (p[j] > p[j + 1])     // " < "从小到大； “ > "从大到小
			{
				t = p[j + 1];
				p[j + 1] = p[j];
				p[j] = t;
			}
		}
	}
}