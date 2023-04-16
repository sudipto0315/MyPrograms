//memory map of structures elements
#include<stdio.h>
int main(int argc, char const *argv[])
{
    struct book
    {
        char name;
        float price;
        int pages;
    };
    struct book b1 ={'B',130.0,550};
    printf("Address of name =%u\n",&b1.name);
    printf("Address of price =%u\n",&b1.price);
    printf("Address of pages =%u\n",&b1.pages);
    return 0;
}
