#include<stdio.h>

int main()
{
    int a,b,c,t; 
    printf("请输入三个数，中间用空格分割：");
    scanf("%d %d %d",&a,&b,&c);
    if(a < b)
    {  
        t = b;
        b = a;
        a = t;
     }   
    if(b < c)
     {   t = c;
        c = b;
        b = t;
     }
     if(a < b)  
    {
       t = a;
        a = b;
        b = t;
         
    }
    
   printf("%d %d %d ",c,b,a);
    return 0;
}