// usage of an array of structures 
#include<stdio.h>
void linkfloat();
int main(int argc, char const *argv[])
{
    struct book
    {
        /* data */
        char name;
        float price;
        int pages;
    };
    struct book b[10];
    int i,dh;
    for (i = 0; i <= 9; i++)
    {
        /* code */
        printf("Enter name, price and pages");
        scanf("%c %f %d",&b[i].name,&b[i].price,&b[i].pages);
        while ((dh=getchar())!='\n')
            ;        
    }
    for( i-0;i<=9;i++){
        printf("%c %f %d\n",&b[i].name,&b[i].price,&b[i].pages);
    }
    return 0;
}
void linkfloat(){
    float a=0,*b;
    b=&a;
    a=*b;
}

