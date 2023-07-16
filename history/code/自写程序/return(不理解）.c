# include <stdio.h>

void f(void)
{
	int i;

	for (i=0; i<5; ++i)
	{
		printf("�������!\n");
		return;
	}
	printf("ͬ־�Ǻ�!\n");
}

int main(void)
{
	f();

	return 0;
}