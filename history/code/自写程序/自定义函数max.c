/*
#include<stdio.h>

void max(int i, int j)

{
    if (i > j)
        printf("%d",i)
    else
        printf("%d",j);
}
int main(void)
 { 
    int a=1, b=2, c=3, d=4, e=5, f=6;
    
    printf("%d",max(a,b,c,d,e,f));
    return 0;
}
*/
# include <stdio.h>

int max(int i, int j)
{
	if (i > j)
	    return i;
	else
		   return j;
}

int main(void)
{
	int a, b, c, d, e, f;

	a = 1, b = 2; c = 3, d = 9, e = -5, f = 100;
	printf("%d\n",max(a, b));

printf("%d\n",max(c, d));

printf("%d\n",max(e, f));
	return 0;
}
