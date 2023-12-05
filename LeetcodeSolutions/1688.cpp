#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {
        long long int match_count = 0;
        long long int tot_match = 0;
        while(n > 1){
            if(n % 2 == 0){
                tot_match = n/2;
                n = n/2;
                match_count += tot_match;
            }
            else{
                tot_match = (n - 1) / 2;
                n = (n - 1) / 2 + 1;
                match_count += tot_match;
            }
        }
        return match_count;
    }
};
int main(){
    Solution s;
    cout << s.numberOfMatches(14) << endl;
    cout << s.numberOfMatches(7) << endl;
    return 0;
}