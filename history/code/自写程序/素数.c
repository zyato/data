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
		printf("������һ��������ֵ:");
		scanf_s("%d", &num);
		if (Prime(num))
			printf("������\n");
		else
			printf("��������\n");
	}
	system("pause");
	return 0;
}
