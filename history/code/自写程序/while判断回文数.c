#include<stdio.h>

int main()
{
    int sum,val,m;//val存放待判断数字
    sum = 0;
    
    printf("请输入需要判断的数字:");
    scanf("%d",&val);
    
    m = val;
    while(m) //非零为真，真则执行while所控制的语句
    {  
        sum = sum*10 + m%10;
        m /= 10;
    }            
    
    if(sum == val)//两个等号判断相等(留心)
        printf("Yes!");
    else
        printf("No!");
      
    return 0;
}