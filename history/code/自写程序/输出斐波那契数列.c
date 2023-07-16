#include<stdio.h>
#include<stdlib.h>
main()
{
	int i=1,j= 1, m = 1, num;
	while (i < 3)
	{
		printf("1\n");
		i++;
	}
	for (i = 3; i <= 20; ++i)


	{
		num = j + m;
		m = j;
		j = num;
		printf("%d\n", num);
	}
	printf("\n");
	system("pause");
	return 0;
}