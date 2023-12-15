#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        set<string> st;
        for(int i=0;i<n;i++){
            st.insert(paths[i][1]);
        }
        for(int i=0;i<n;i++){
            if(st.count(paths[i][0])>0)
                st.erase(paths[i][0]);
        } 
        for(string destination:st){
            return destination;
        }     
        return "";
    }
};
int main(){
    Solution s;
    vector<vector<string>> paths1={{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    cout<<s.destCity(paths1)<<endl;
    vector<vector<string>> paths2={{"B","C"},{"D","B"},{"C","A"}};
    cout<<s.destCity(paths2)<<endl;
    vector<vector<string>> paths3={{"A","Z"}};
    cout<<s.destCity(paths3)<<endl;
    return 0;
}