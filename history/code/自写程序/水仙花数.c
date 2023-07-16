#include<stdio.h>

int main()
{  
    int number,i1,i2,i3,j; 
    for(number=100;number<1000;++number)
   {
        i1=number/100;
        j=number%100;
        i2=j/10;
        i3=j%10;
        if(number==i1*i1*i1+i2*i2*i2+i3*i3*i3)
        {
         printf("%d\n",number);
        }
    }
    return 0;
}