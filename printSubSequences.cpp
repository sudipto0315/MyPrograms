#include <iostream>
#include <vector>
using namespace std;
void printF(int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // not pick, or not take condition,this elemnt is not added to your subsequence
    printF(ind + 1, ds, arr, n);

    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the length of the arr: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    cout << endl;
    vector<int> ds;
    printF(0, ds, arr, n);
    return 0;
}
