#include <iostream>
#include <vector>
using namespace std;
int highestAltitude(vector<int>& height) {
    int highest = 0;
    int currentAltitude = 0;

    for (int h : height) {
        currentAltitude += h;
        if (currentAltitude > highest) {
            highest = currentAltitude;
        }
    }

    return highest;
}

int main(int argc, char const *argv[])
{
    int size= 0;
    cout << "Enter the size of the element: ";
    cin >> size;
    // enter the elements
    vector<int> height(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> height[i];
    }
    int highest = highestAltitude(height);
    cout << "Highest Altitude: " << highest << endl;
    return 0;
}