#include <iostream>
using namespace std;

int findMax(int arr[], int left, int right)
{
    if (left == right)
    {
        return arr[left];
    }

    int mid = left + (right - left) / 2;
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    return max(maxLeft, maxRight);
}
int findMin(int arr[], int left, int right)
{
    if (left == right)
    {
        return arr[left];
    }

    int mid = left + (right - left) / 2;
    int maxLeft = findMin(arr, left, mid);
    int maxRight = findMin(arr, mid + 1, right);

    return min(maxLeft, maxRight);
}
void findMaxAndSecondMax(int arr[], int left, int right, int &maxVal, int &secondMaxVal)
{
    if (left == right)
    {
        maxVal = arr[left];
        secondMaxVal = -1;
        return;
    }

    int mid = left + (right - left) / 2;
    int leftMax, leftSecondMax;
    int rightMax, rightSecondMax;

    findMaxAndSecondMax(arr, left, mid, leftMax, leftSecondMax);
    findMaxAndSecondMax(arr, mid + 1, right, rightMax, rightSecondMax);

    maxVal = max(leftMax, rightMax);
    secondMaxVal = max(min(leftMax, rightMax), max(leftSecondMax, rightSecondMax));
}

int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int secondMaxElement;
    int maxElement = findMax(arr, 0, n - 1);
    int minElement = findMin(arr, 0, n - 1);
    cout << "Maximum element in the array: " << maxElement << endl;
    findMaxAndSecondMax(arr, 0, n - 1, maxElement, secondMaxElement);
    cout << "Minimum element in the array: " << minElement << endl;
    cout << "Second maximum element in the array: " << secondMaxElement << endl;

    return 0;
}
