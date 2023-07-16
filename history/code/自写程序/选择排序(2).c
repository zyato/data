#include<stdio.h>

int main()
{   
    int i,j;
    int maxIndex;
    int temp;
    int arr[10] = {4,5,4,6,1,3,9,2};
    for(i=0;i<9;++i)
    {
        maxIndex=i;
        for(j=i+1;j<10;++j)
        {
            if(arr[maxIndex]<arr[j])
                maxIndex=j;
        }
        if(maxIndex != i)
        {
            temp=arr[maxIndex]  ;
            arr[maxIndex]=arr[i] ;
            arr[i]=temp;
        }
    }
    for(i=1;i<10;++i)
    {
        printf("%-3d",arr[i]);
    }
    return 0;
}