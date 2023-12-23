#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        unordered_set<string>s;
        s.insert("0,0");
        for(char c:path){
            if(c=='N') y++;
            else if(c=='S') y--;
            else if(c=='E') x++;
            else x--;
            string cord=to_string(x)+","+to_string(y);
            if(s.find(cord)!=s.end()){
                return true; // if the path crosses
            }
            s.insert(cord);
        }
        return false; // if no crossings are found
    }
};
int main(){
    Solution s;
    cout << s.isPathCrossing("NES") << endl;
    cout << s.isPathCrossing("NESWW") << endl;
    return 0;
}