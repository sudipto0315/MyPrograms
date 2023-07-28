#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    //v=<1,2,3>

    //printing
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
    vector<int>::iterator it;
    for (it=v.begin();it<v.end();it++)
    {
        cout<<*it<<endl;
    }
    
    for(auto element:v){
        cout<<element<<endl;
    }
    return 0;
}
