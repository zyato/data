#include<stdio.h>
#include<stdlib.h>

int Prime(int num)
{
	int i;
	for (i = 2; i <= num; ++i)
	{
		if (num%i == 0)
			break;
	}
	if (i == num)
		return 1;
	else
		return 0;
}
int main(void)
{
	while (1)
	{
		int num;
		printf("请输入一个整数数值:");
		scanf_s("%d", &num);
		if (Prime(num))
			printf("是素数\n");
		else
			printf("不是素数\n");
	}
	system("pause");
	return 0;
}
