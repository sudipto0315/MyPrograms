#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int alt = 0;
        for(int i=0; i < gain.size(); i++){
            alt += gain[i];
            if(alt > highest){
                highest = alt;
            }
        }
        return highest;
    }
};
int main(){
    Solution s;
    vector<int> gain = {-5,1,5,0,-7};
    cout << s.largestAltitude(gain) << endl;
    return 0;
}