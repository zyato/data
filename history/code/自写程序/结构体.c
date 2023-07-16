/*Learning tips
 1. pst->age在计算机内部会被转化为(*pst).age

*/
#include<stdio.h>
struct Student
    {
        int age;
        double score;
        char sex;
    };
void InputStudent(struct Student *) ;
void OutputStudent(struct Student ) ; 
int main()
{    
    struct Student st;
    InputStudent(&st);
    OutputStudent(st);
    return 0;
}
void InputStudent(struct Student * pst)
{
    (*pst).age=20;
    pst->score=120;
    pst->sex='F';
}
void OutputStudent(struct Student st)
{
  printf("%d %f %c", st.age, st.score, st.sex);
}