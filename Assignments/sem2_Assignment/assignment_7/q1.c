#include <stdio.h>
#include <string.h>

void getInput(char str[25][25], int count)
{
    int i;
    printf("Enter strings one by one:\n");
    for (i = 0; i < count; i++)
    {
        scanf("%s", str[i]);
    }
}

void sortStrings(char str[25][25], int count)
{
    int i, j;
    char temp[25];
    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

void printStrings(char str[25][25], int count)
{
    int i;
    printf("Order of Sorted Strings:\n");
    for (i = 0; i < count; i++)
    {
        puts(str[i]);
    }
}

int main()
{
    int count;
    printf("How many strings are you going to enter?: ");
    scanf("%d", &count);

    char str[25][25];
    getInput(str, count);
    sortStrings(str, count);
    printStrings(str, count);

    return 0;
}
