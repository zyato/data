#include<stdio.h>
#include<stdlib.h>

void InPut(int *, int);//����
void OutPut(int *, int);//���
void Sort(int *, int);//����

int main(void)
{
	int lon;
	printf("��������ֵ�ĸ�����");
	scanf_s("%d", &lon);
	int * a = (int *)malloc(sizeof(int)*lon);

	InPut(a, lon);
	Sort(a, lon);
	printf("�������ǣ�\n");
	OutPut(a, lon);

	system("pause");
	return 0;
}
void InPut(int * p, int lon)
{
	int i;
	printf("������%d������", lon);
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
			if (p[j] > p[j + 1])     // " < "��С���� �� > "�Ӵ�С
			{
				t = p[j + 1];
				p[j + 1] = p[j];
				p[j] = t;
			}
		}
	}
}