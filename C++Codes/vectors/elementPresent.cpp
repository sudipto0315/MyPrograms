//if an element is present in the array or not
//given Q queries, check if the given number is present in the array or not
//NOTE: Value of all the elements in the array is less than 10 to the power 5 (10^5).
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements in the vector: ";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i<<" element: ";
        cin>>v[i];
    }
    const int N = 1e5+10; //given constrain(10^5)
    vector<int> freq(N,0);  //this is a frequency array (Hashmap Method)
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;        //freq[v[i]]=freq[v[i]]+1
    }
    
    cout<<"Enter no queries";
    int q; cin>>q;
    while (q--)
    {
        int queryElement;
        cout<<"Enter the query element to search its frequency: ";
        cin>>queryElement;
        cout<<freq[queryElement]<<endl;
    }
    
    return 0;
}
