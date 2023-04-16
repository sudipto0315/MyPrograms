//Armstrong Number
#include <stdio.h>
#include<conio.h>
int main(int argc, char const *argv[])
 {
    int num, originalNum, remainder, result=0;
    printf("Enter a three-digit integer :");
    scanf("%d",&num);
    originalNum= num;
    while (originalNum!= 0){
        //remainder contain the last digit
        remainder=originalNum%10;
        result+=remainder*remainder*remainder;
        //remainder last digit from the original number
        originalNum/=10;
    }
    if (result==num){
        printf("%d is an armstrong number. ", num);
    }
    else{
        printf("%d is not an armstrong number. ", num);
    }
    return 0;
}
 
