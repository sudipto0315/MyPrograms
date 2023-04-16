#include<stdio.h>
static void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
    printf("a=%d, b=%d\n",a,b);
}  
void main(){
    int a=0,b=1;
    swap(a,b);
    printf("a=%d, b=%d\n",a,b);
}