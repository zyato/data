# include <stdio.h>

int main(void)
{
    int val;
 printf("请输入要进入的楼层: ");
 scanf("%d", &val);

	switch (val)
	{
	case 1:
		   printf("1层开!\n");
	    	break;
	case 2:
	    	printf("2层开!\n");
	    break;
	case 3:
	    	printf("3层开!\n");
	    	break;
 default:
		    printf("没有盖到这一层!\n");
	    	break;
	}

	    return 0;
}
/*
            （官方解释）执行完一个case 语句后，
            流程控制就转移到下一个case字
            句继续执行。“case"常量表达式
            只是起语句标号的作用，并不是在
            该处进行条件判断。在执行swtich
            语句时，根据switch()中表达式
            的值找到与之匹配的case子句，就
            从此case子句开始执行下去，不
            再进行判断。
        ①case和default后是冒号
        ②switch是选择语句，进入入口后，从上到下依次执行
        ③break退出swith，并转去执行switch下面的语句
        ④注释掉break会继续向下执行
                如把前三个break注释掉，输入1
            则会输出"1层开，2层开，3层开，没盖
            到这一层"。
            switch(i)
            {
            case 1:  语句1;
            case 2:  语句2;
            default :语句3;
            case 3:  语句4;}
            当i==1时，从case1处开始往下一
            个不落的执行，当i==2时 从case2
            处开始往下一个不落的执行，当
            i==3时， 只执行case3一句，当
            i==4时，从default处开始往下
            一个不落的执行，当i==0时 执行
            情况同i= =4。

                
*/