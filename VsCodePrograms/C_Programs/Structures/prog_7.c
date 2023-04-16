#include<stdio.h>
int main(int argc, char const *argv[])
{
    struct address
    {
        /* data */
        char phone[15];
        char city[25];
        int pin;
    };
    struct emp
    {
        /* data */
        char name[25];
        struct address a;
    };
    struct emp e ={"jeru","781015","guwahati",10};
    printf("name=%s phone=%s\n",e.name,e.a.phone); 
    return 0;
}