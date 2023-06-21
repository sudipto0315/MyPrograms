//find the total number of pairs in the Array whose sum is 
//equal to the given value of targetSum
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int array[]={3,4,6,7,1};
    int targetSum=7;
    int size=sizeof(array)/sizeof(array[0]);
    int pairs=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i]+array[j]==targetSum)
            {
                pairs++;
            }
        }
    }
    cout<<"There are "<<pairs<<" pairs whose target sum is "<<targetSum<<endl;
    return 0;
}
