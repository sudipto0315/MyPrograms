#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> table(26,-1);
        int count=0;
        for(int i=0;i<key.size();i++){
            if(key[i] != ' ' && table[key[i]-'a'] == -1){
                table[key[i]-'a'] = count++;
            }
        }
        for(int i=0;i<26;i++){
            cout << table[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < message.size(); i++){
            if(message[i] != ' '){
                message[i] = table[message[i]-'a'] + 'a';
            }
        }
        return message;
    }
};
int main(){
    Solution s;
    cout << s.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv") << endl;
    return 0;
}