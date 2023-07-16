#include<stdio.h>
#define A 5
int main(void)
{
	float b,avg,d; //单个学生成绩  平均成绩  总成绩
	int i;
	for(i=0,d=0;i<A;i++)
	{
	    printf("输入%d个学生的成绩:\n",i+1);
	    scanf("%f",&b);
	    d+=b;
	    	  	}
	avg=d/A;
	printf("学生的总成绩:%0.2f\n",d);
	printf("学生的平均成绩是:%0.2f\n",avg);
	return 0;
	 
 } 