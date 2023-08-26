// #include <iostream>
// using namespace std;
// int peakElement(int arr[], int left,int right)
// {
//     if (left==right)
//     {
//         return left;
//     }
//     int mid = left + (right-left)/2;  
//     if (arr[mid-1]<arr[mid])
//     {
//         return peakElement(arr,mid+1,right);
//     }
//     else if(arr[mid]>arr[mid+1])
//     {
//         return peakElement(arr,left,mid-1);
//     }
    
// }
// int main(int argc, char const *argv[])
// {
//     int size = 0;
//     cout << "enter the size of the input array: ";
//     cin >> size;
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         cout << "Enter the " << i << " element:";
//         cin >> arr[i];
//     }
//     int peak = peakElement(arr,0,size-1);
//     cout<<"The peak element is: "<<peak<<endl;
//     return 0;
// }
#include <iostream>
using namespace std;

int peakElement(int arr[], int left, int right) {
    if (left == right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] < arr[mid + 1]) {
        return peakElement(arr, mid + 1, right);
    } else {
        return peakElement(arr, left, mid);
    }
}

int main(int argc, char const *argv[]) {
    int size = 0;
    cout << "Enter the size of the input array: ";
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    
    int peak = peakElement(arr, 0, size - 1);
    cout << "The peak element is: " << arr[peak] << endl;
    
    return 0;
}
