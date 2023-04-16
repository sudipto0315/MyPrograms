#include <stdio.h>
void main(){
    int number,
        previous_number,
        index = 1,
        flag = 1;
    printf("Please enter five integers");
    printf("seperated by a carriage return. \n");
    scanf("%d",&previous_number);

    while (index < 5)
    {
        scanf("%d",&number);
        index += 1;
        if (number < previous_number)
        {
            printf("The number in position %d is out of order. \n", index);
        }
        else
        {
            flag += 1;
            previous_number=number;
        } 
    }
    printf("%d of the numbers are in ascending order. \n",flag);
}
