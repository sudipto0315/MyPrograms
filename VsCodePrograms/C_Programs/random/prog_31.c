#include<stdio.h>
int f(int n,int sum){
    return n==0?sum:f(n/10,sum*10+n%10); //testCondition ? expression1 : expression 2;
}
int main(){
    int n = 54321;
    int ans = f(n,0);
    printf("%d \n",ans);
}