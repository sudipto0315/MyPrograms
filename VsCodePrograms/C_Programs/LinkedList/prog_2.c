#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main(int argc, char const *argv[])
{
    struct node *head=malloc(sizeof(struct node));
    head->data=55;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    head->data=98;
    head->link=NULL;
    printf("%d",head->data);
    return 0;
}

 