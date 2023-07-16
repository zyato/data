#include<stdio.h>
#include<stdlib.h>
main()
{
	int i, j;
	for (i = 1; i < 100; ++i)
	{
		for (j = 2; j <= i; ++j)
		{
			if (0 == i % j)break;
		}
		if (j == i)printf("%3d", i);
	}
	system("pause");
	return 0;
}