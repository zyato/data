#include<stdio.h>
#include<math.h>

int main()
{
    int a = 1 ;
    int b = 4 ;
    int c = 4 ;
    float delta ;
    float x1;
    float x2;
    delta = b*b - 4*a*c;
    
    if(delta > 0)
    {
    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);
    printf("有两根，x1 = %f, x2 = %f", x1,x2);
    }
    else if(delta == 0)
    {
       x1 = (-b) / (2*a);
       x2 = x1;
       printf("两等根 ，x1 = x2 = %f",x1);
    }
    else
    {
       printf("无解");
    }
    return 0;
}