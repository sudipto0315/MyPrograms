#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int array[]={3,4,6,7,1,3};
    int targetSum=7;
    int size=sizeof(array)/sizeof(array[0]);
    int triplets=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            for (int k = j+1; k < size; k++)
            {            
                if (array[i]+array[j]+array[k]==targetSum)
                {
                    triplets++;
                }
            }
        }
    }
    cout<<"There are "<<triplets<<" pairs whose target sum is "<<targetSum<<endl;
    return 0;
}
