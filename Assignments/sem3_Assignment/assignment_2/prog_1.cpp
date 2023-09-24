#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of the input array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the input array: ";
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	//as the arr is sorted but we dont know the order
	//so check the first and last element

	if (arr[0]<arr[n-1])
	{
		cout<<"The maximum element in the array is "<< arr[n-1]<<" and the array is in assencing order."<<endl;
	}
	else if (arr[0]>arr[n-1])
	{
		cout<<"The maximum element in the array is "<< arr[0] <<" and the array is in decending order."<<endl;

	}
	
	return 0;
}
