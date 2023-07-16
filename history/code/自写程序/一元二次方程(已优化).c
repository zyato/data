#include<stdio.h>
#include<math.h>

int main(void)
{
    int a,b,c;
    float delta,x1,x2;
    char ch;
    
    do
    {
        printf("请输入a的值 a=");
        scanf("%d",&a);
        printf("请输入b的值 b=");
        scanf("%d",&b);
        printf("请输入c的值 c=");
        scanf("%d",&c);
        
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
       
        printf("继续请输入y,输入其他字母则退出");  
        scanf(" %c",&ch);   /*%c前必须留空格，否则不能输入字母
                        								%c前必须留空格，否则不能输入字母
    	   	                 							%c前必须留空格，否则不能输入字母
    			                   		 				%c前必须留空格，否则不能输入字母
    			                   							%c前必须留空格，否则不能输入字母
                      										 %c前必须留空格，否则不能输入字母
                       										%c前必须留空格，否则不能输入字母
    		                    								*/
     }
        while('y' == ch || 'Y' == ch);
    return 0;
}