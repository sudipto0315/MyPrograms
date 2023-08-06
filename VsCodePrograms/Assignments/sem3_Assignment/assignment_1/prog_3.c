#include <stdio.h>
#include <string.h>

// Function to multiply two decimal numbers represented as strings
void multiply(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_result = len1 + len2;

    // Initialize the result array with '0'
    for (int i = 0; i < len_result; i++)
    {
        result[i] = '0';
    }
    result[len_result] = '\0';

    // Perform multiplication digit by digit
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = temp / 10;
            result[i + j + 1] = (temp % 10) + '0';
        }
        result[i] = carry + '0';
    }

    // Remove leading zeros in the result
    int i = 0;
    while (result[i] == '0')
    {
        i++;
    }
    printf("The result is: ");
    if (i == len_result)
        printf("%d\n", 0);
    else
    {

        // Shift the result to remove leading zeros
        for (int j = i; j < len_result; j++)
        {
            printf("%c", result[j]);
        }
        printf("\n");
    }
}

int main()
{
    char num1[100], num2[100], result[200];

    // Input the first decimal number as string
    printf("Enter the first decimal number: ");
    scanf("%s", num1);

    // Input the second decimal number as string
    printf("Enter the second decimal number: ");
    scanf("%s", num2);

    // Perform multiplication
    multiply(num1, num2, result);

    // Print the result
    // printf("The product is: %s\n", result);

    return 0;
}
