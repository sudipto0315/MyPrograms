// #include <stdio.h>
// #include <string.h>
// void main(void) {
// 	char strbuffer[8] = "bbbbbbb";
// 	char str1[] = "CodeTantra";
// 	str1[3] = '\0';
// 	strcpy(strbuffer, str1);
// 	printf("%s\n",strbuffer);
//  }
#include<stdio.h>
void main(){
    int i=5;
	int a = ++i;
	int b = ++i;
    //i= ++i + ++i;
	i = a+b;
    printf("%d",i);
}
