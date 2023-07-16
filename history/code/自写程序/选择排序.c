#include<stdio.h>
#include<stdlib.h>
void Input(int * p, int num);
void Output(int * p, int num);
void Sort(int * p , int num);
int main(void)
{
	int num;
	printf("请输入所需排序数的个数：");
	scanf_s("%d", &num);
	int * p = (int *)malloc(sizeof(int)*num);
	Input(p, num);
	Sort(p, num);
	printf("排序结果是：\n");
	Output(p, num);
	system("pause");
	return 0;
}
void Input(int * p, int num)
{
	int i;
	for(i = 0; i < num; ++i)
		scanf_s("%d", p+i);
}
void Output(int * p, int num)
{
	int i;
	for(i = 0; i < num; ++i)
		printf("%d   ", p[i]);
}
void Sort(int * p, int num)
{
	int i, j, t;
	for(i=0;i<num;++i)
		for(j=i+1;j<num;++j)
			if(p[i] > p[j])
			{
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
}