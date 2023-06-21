//rotating a given vector by k steps
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v={1,2,3,4,5};
    int k=2;
    if (k >= v.size())
        k=k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(int a:v)
    {
        cout<<a;
    }
    return 0;
}
