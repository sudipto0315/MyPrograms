#include<stdio.h>
struct stduent
{
    char name[100];
    int roll;
}s1,s2;
int compareName(struct student s1,struct student s2){
    return strcmp(s1.name,s2.name);
}
void sort (struct student s[5],int compare(struct student s1,struct student s2))
{
    for(int i =0;i<5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (compare(s[i],s[j])>0)
            {
                struct student temp = s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    struct student s[5];
    for (int i=0;i<5;i++){
        printf("Enter name\n");
        gets(s[i].name);
        fflush(stdin);
        printf("Enter roll\n");
        scanf("%d",&s[i].roll);
        fflush(stdin);
    }
    sort(s,compareName);
    for (int i = 0; i < 5; i++)
    {
        printf("the roll of %d %d ")
    }
    
    return 0;
}
