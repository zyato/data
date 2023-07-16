#include<stdio.h>
void sort(int *, int);
void Output(int *, int);
int main()
{
    int i, a[9]={1,0,-3,-33,95,36,-999};
    sort(a, 9);
    Output(a, 9);
    return 0;
}
void sort(int * a, int Long)
{
    int i,j,t;
    for(i=0; i<Long-1; ++i)
    {
        for(j=0; j<Long-i-1; ++j)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void Output(int * a, int Long)
{
    int i;
    for(i=0; i<Long-1; ++i)
    {
        printf("%4d",a[i]);
    }
    
}
