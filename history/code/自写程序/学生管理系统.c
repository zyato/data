#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 1000//最大能存入多少管理对象
int Count = 0;
struct Tem//定义结构体变量 
{	
    char node[30];//学号 	
    char name[30];//姓名 	
    int age;	//年两 	
    char sex[30];//性别 	
    char address[30];//地址 	
    char tel[30];//电话 	
    char birth[30];//生日 	
    char email[30];//邮箱 	
    int status;//状态标志，0为不存在，非反
 }tem[MAXN], temp;//第一个学生群体数组，第二个交换的中间变量 
void sort()//排序函数，通过比较学号的大小进行的排序
 {	
    for (int i = 0; i < Count; i++)	
    {		
        for (int j = i + 1; j < Count; j++)	
        	{			
            if (strcmp(tem[i].node, tem[j].node) > 0)			
            {				
                temp = tem[j];				
                tem[j] = tem[i];				
                tem[i] = temp;			
            }
       		}
    	}
 }
void show()//展示信息函数 
{	
    sort(); //排序 
    	int b = 0;	
    for (int i = 0; i < Count; i++)	
    {	
        	if (tem[i].status)		
         {		
             	printf("#%d:\n", ++b);//序号为1，不等同于学号为1 			
            printf("node：%s\n", tem[i].node);		
            	printf("name：%s\n", tem[i].name);			
            printf("sex：%s\n", tem[i].sex);			
            printf("address：%s\n", tem[i].address);			
            printf("tel：%s\n", tem[i].tel);		
            	printf("age：%d\n", tem[i].age);		
            	printf("birth：%s\n", tem[i].birth);			
            printf("email：%s\n", tem[i].email);	
         	}	
    }
}
void insert_function()//增加函数
{
    	printf("请输入学号：\n");	
    scanf("%s", tem[Count].node);		//a[0]a[1]a[2]	
    printf("请输入姓名：\n");
    	scanf("%s", tem[Count].name);
    	printf("请输入性别：\n");	
    scanf("%s", tem[Count].sex); 
    ;	printf("请输入地址：\n");
    	scanf("%s", tem[Count].address);
    	printf("请输入电话：\n");	
    scanf("%s", tem[Count].tel);	
    printf("请输入年龄：\n");	
    scanf("%d", &tem[Count].age);	
    printf("请输入生日：\n");	
    scanf("%s", tem[Count].birth);	
    printf("请输入电子邮箱：\n");	
    scanf("%s", tem[Count].email);	
    tem[Count].status = 1;//通过该数据的1||0来调配数据的存在 	
    Count++; 
}
void find_function()//查找函数
{	
    int flag = 0;
    	char Name[30];	
    printf("请输入是node：\n");
    	scanf("%s", Name);	
    for (int i = 0; i < Count; i++)
    	{		
        if (strcmp(Name, tem[i].node) == 0 && tem[i].status)//通过对比学号相同查找所求学生信息
        {			
            flag = 1;		
            	printf("学号：%s\n", tem[i].node);		
            	printf("姓名：%s\n", tem[i].name);		
            	printf("性别：%s\n", tem[i].sex);		
            	printf("地址：%s\n", tem[i].address);			
            printf("电话：%s\n", tem[i].tel);			
            printf("年龄：%d\n", tem[i].age);			
            printf("生日：%s\n", tem[i].birth);		
            	printf("电子邮箱：%s\n", tem[i].email);			
            break;//找到以后终止循环，停继续查找 		
         }	
       
    }	
    if (!flag)//文件结尾也没有找到 
    	{		
        printf("查无此人\n");
     	}
}void del_function()//删除函数
{
    	int flag = 0;
	    char Name[30];	
    printf("请输入学号：\n");
    	scanf("%s", Name);
    	for (int i = 0; i < Count; i++)	
    {		
        if (strcmp(Name, tem[i].node) == 0 && tem[i].status)		
        {			
            flag = 1;			
            printf("学号：%s\n", tem[i].node);			
            printf("姓名：%s\n", tem[i].name);			
            printf("性别：%s\n", tem[i].sex);			
            printf("地址：%s\n", tem[i].address);		
            	printf("电话：%s\n", tem[i].tel);		
            	printf("年龄：%d\n", tem[i].age);			
            printf("生日：%s\n", tem[i].birth);	
          		printf("邮箱：%s\n", tem[i].email);			
            tem[i].status = 0;//通过该数据判断存在问题 			
            printf("已删除\n");
           
         			break;		
        }
    	}	
        if (!flag)
        	{		
            printf("查无此人\n");
         	}
}
void change_function()//修改函数
{	
    int flag = 0;	
    char Name[30];	
    printf("请输入是学号：\n");
    	scanf("%s", Name);	
    for (int i = 0; i < Count; i++)	
    {	
        	if (strcmp(Name, tem[i].node) == 0 && tem[i].status)//123 223		
        {
          			flag = 1;			
            printf("学号：%s\n", tem[i].node);
          			printf("姓名：%s\n", tem[i].name);			
            printf("性别：%s\n", tem[i].sex);		
            	printf("地址：%s\n", tem[i].address);			
            printf("电话：%s\n", tem[i].tel);			
            printf("年龄：%d\n", tem[i].age);		
            	printf("生日：%s\n", tem[i].birth);			
            printf("邮箱：%s\n", tem[i].email);			
            printf("请输入学号：\n");			
            scanf("%s", tem[i].node);			
            printf("请输入姓名：\n");			
            scanf("%s", tem[i].name);			
            
            printf("请输入性别：\n");			
            scanf("%s", tem[i].sex); ;		
            	printf("请输入地址：\n");			
            scanf("%s", tem[i].address);		
            	printf("请输入电话：\n");	 
            scanf("%s", tem[i].tel);		
            	printf("请输入年龄：\n");		
            	scanf("%d", &tem[i].age);		
            	printf("请输入生日：\n");			
            scanf("%s", tem[i].birth);		
            	printf("请输入邮箱：\n");			
            scanf("%s", tem[i].email);		
            	break; 
       	}	
    }
    	if (!flag)	
    {		
        printf("查无此人\n");	
    }
}
void save_function()//储存文件函数
{	
    FILE *fp = fopen("save.txt", "w+");//打开文件 	
    for (int i = 0; i < Count; i++)	
    {		
        fprintf(fp, "%s %s %s %s %s %s %s %d %d\n", tem[i].node, tem[i].name, tem[i].sex, tem[i].address, tem[i].tel, tem[i].birth, tem[i].email, tem[i].age, tem[i].status);	
    }
    	fclose(fp);//关闭文件 
}
void read_function()//读取文件函数
{	
    FILE *fp = fopen("save.txt", "r");//打开文件 	
    if (fp == NULL)
    	{		
        fp = fopen("save.txt", "w+");		
        fclose(fp);//关闭文件 		
        return;
    	}	
    Count = 0;
    	while (!feof(fp))	
    {		
        int a;		
        fscanf(fp, "%s %s %s %s %s %s %s %d %d\n", &tem[Count].node, &tem[Count].name, &tem[Count].sex, &tem[Count].address, &tem[Count].tel, &tem[Count].birth, &tem[Count].email, &tem[Count].age, &tem[Count].status);		
        Count++;
       
    
    
    	}	
    fclose(fp);
}
void menu_menu(int i)
{				
    switch (i)		
    {		
        case 1:			system("cls");//system("") 清屏 			
                 insert_function();			
                 system("pause");			
                 system("cls");			
                 break;		
        case 2:			
                system("cls");			
                del_function();			
                system("pause");			
                system("cls");			
                break;		
         case 3:			system("cls");			
                  change_function();		
                  	system("pause");		
                  	system("cls");			
                 break;		
         case 4:			system("cls");			
                  find_function();			
                  system("pause");		
                  	system("cls");			 
                   break;		
         case 5:			system("cls");			
                  show();			
                  system("pause");		
                  	system("cls");			
                  break;		
         default:			save_function();			
                   exit(0);			
                   break;		
         
     }
  

}
void menu()
{		
    printf("\t\t\t\t学生信息管理系统\n");	
    	printf("\t\t\t\t 1.增加学生信息\n");		
    printf("\t\t\t\t 2.删除学生信息\n");		
    printf("\t\t\t\t 3.修改学生信息\n");	
    	printf("\t\t\t\t 4.查询学生信息\n");		
    printf("\t\t\t\t 5.展示学生信息\n");		
    printf("\t\t\t\t  0.退出系统\n");		
    printf("请选择：\n");	
    
    
}
int main()
{	
    read_function();
    	while (1)
    	{		
        int i;	
        	menu();		
        scanf("%d", &i);		
        menu_menu(i);
     	}	
     return 0;
}