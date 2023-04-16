//sum of the elements in a array
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void main ( )
{
    system("cls");
    int i, a[5],sum=0;
    //clrscr();
    printf ("Enter the elements\n");
    
    for (i=0; i< 5; i++)
    {
        scanf ("%d", &a [i]);
        sum = sum + a[i];
    }
printf ("The sum of the array elements is %d ",sum);
getch();
}
