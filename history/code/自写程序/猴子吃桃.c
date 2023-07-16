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
	printf("第一天一共摘了%d个桃子\n", num);
	system("pause");
	return 0;
}