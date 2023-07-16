#include<stdio.h>

void swap(int *, int *);
int main(void)
{
    int a = 3, b = 5;
    swap(&a,&b);
    printf("a = %d, b = %d",a,b);
    return 0;
}
void swap(int * p, int * q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
    return;
    
    }