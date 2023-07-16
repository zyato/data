#include<stdio.h>
#include<stdlib.h>
main()
{
	int num, a[3];
	for (num = 100; num < 1000; ++num)
	{
		a[0] = num / 100;
		a[1] = (num % 100) / 10;
		a[2] = (num % 100) % 10;
		if ((a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2]) == num)
			printf("%d\n", num);
	}
	system("pause");
	return 0;
}