#include<stdio.h>
int main(int argc, char const *argv[])
{
    struct Student
    {
        char name[20];
        int roll;
        char sex[20];
        double gpa;
    }student;
    printf("enter: ");
    scanf("%s%d%s%lg",&student.name,&student.roll,&student.sex,&student.gpa);
    printf("\nAnd this is what you entered");
    printf("\n %s %d %s %lg",student.name,student.roll,student.sex,student.gpa);
    return 0;
}
