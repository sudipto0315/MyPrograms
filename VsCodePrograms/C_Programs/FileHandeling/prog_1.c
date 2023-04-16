//printing a file
#include<stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    char ch;
    fp = fopen("pr1.c","r");
    // while (1)
    // {
    //     ch =fgetc(fp);
    //     if(ch==EOF)
    //         break;
    //     printf("%c",ch);
    // }

    // ch =fgetc(fp);
    // while (ch!=EOF)
    // {
    //     printf("%c",ch);
    //     ch =fgetc(fp);
    // }

    // while (!feof(fp))
    // {
    //     ch =fgetc(fp);
    //     printf("%c",ch);
    // }
    printf("\n");
    fclose(fp);
    return 0;
}
