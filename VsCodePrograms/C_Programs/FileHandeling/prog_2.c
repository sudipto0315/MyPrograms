//Count characters, tabs, spaces and lines
#include<stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    char ch;
    int nol, not, nob, noc=0;
    //noc -> No of Characters
    //nob -> No of Blanks
    //not -> No of tabs
    //nol -> No of lines
    fp=fopen("pr1.c","r");
    while (1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        noc++;
        if(ch==' ')  
            nob++; 
        if(ch=='\n')
            nol++;
        if(ch=='\t')  
            not++;        
    }
    fclose(fp);
    printf("No of Characters=%d\n",noc);
    printf("No of Blanks=%d\n",nob);
    printf("No of Tab=%d\n",not);
    printf("No of lines=%d\n",nol);
    return 0;
}
