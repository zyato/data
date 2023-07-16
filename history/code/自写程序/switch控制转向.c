#include<stdio.h>
#include<stdlib.h>
int aa(int);
main()
{
	int ldg, rdg,s,max=1000,min=0;
	scanf_s("%d", &ldg);
	scanf_s("%d", &rdg);
	switch (aa(ldg))
	{
	case 0:
		ldg = max; break;
	case 1:
		ldg = min; break;
	case 2:
		ldg = ldg; break;

	}
	switch (aa(rdg))
	{
	case 0:
		rdg = max; break;
	case 1:
		rdg = min; break;
	case 2:
		rdg = rdg; break;

	}
	if (ldg > rdg)s = 0;
	else if (ldg <rdg)s = 1;
	else s = 2;
	switch (s)
	{
	case 0:printf("left"); break;
	case 1:printf("right"); break;
	case 2:printf("buzhuan"); break;
	}
	system("pause");
	return 0;
}
int aa(int dg)
{
	int max = 1000, min = 0, h;
	if (dg > max) h = 0;
	else if (dg < min) h = 1;
	else h = 2;
	return h;
}
