//using gets() and Puts()
#include<stdio.h>
#include<string.h>
int using_Puts(){
    char str[] ="Programing is best";
    printf("printing using printf() -> %s \n",str);//printing with printf
    printf("printing using puts() -> ");
    puts(str); //only used for printing strings
    //automatically adds a \n to the end
    return 0;
}
int using_Gets(){
    char str[40];
    printf("enter: ");
    //scanf("%s",str); //only the first word will be considered
    //using [^\n] //it takes 
    //scanf("%[^\n]s",str); //this is a dirty way to take string input using scanf
    gets(str);
    printf("Your input was: %s",str);
    return 0;
}
int main(int argc, char const *argv[])
{
    using_Puts();
    using_Gets();
    return 0;
}
