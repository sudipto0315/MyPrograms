#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    char str[80];
    fp=fopen("poem.txt","w");
    if (fp==NULL)
    {
        puts("Cannot open file");
        exit (1);
    }
    printf("\nEnter a few lines of text:\n");
    while (strlen(gets(str))>0)
    {
        fputs(str,fp);
        fputs("\n",fp);
    }
    fclose(fp);
    //read the file bac
    printf("\nFile contents are being read now...\n");
    fp=fopen("poem.txt","r");
    if (fp==NULL)
    {
        puts("Cannot open file");
        exit(1);
    }
    while (fgets(str,79,fp)!=NULL)
        printf("%s",str);
    fclose(fp);
    return 0;
}
