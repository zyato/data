#include<stdio.h>
#include<stdlib.h>
main()
{
	int i, j=1, num;
	for (i = 10; i > 1; --i)
	{
		num = (j + 1) * 2;
		j = num;
	}
	printf("��һ��һ��ժ��%d������\n", num);
	system("pause");
	return 0;
}