#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int lengthChars=chars.size();
        int wlength=words.size();
        vector<int>ans(wlength,1);
        for(int i=0;i<wlength;i++){
            int lengthWord=words[i].size();
            string str=words[i];
            vector<int>vis(lengthChars,-1);
            for(int j=0;j<lengthWord;j++){
                char ch=str[j];
                int val=0;
                for(int k=0;k<lengthChars;k++){
                    if(chars[k]==ch && vis[k]==-1){
                        vis[k]=1;
                        val=1;
                        break;
                    }
                }
                if(val==0){
                    ans[i]=-1;
                    break;
                }
            }
        }
        int lengthAns=0;
        for(int i=0;i<wlength;i++){
            if(ans[i]!=-1){
                lengthAns=lengthAns+words[i].size();
            }
        }
        return lengthAns;
    }
};

int main()
{
    // Example usage
    Solution solution;
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    int result = solution.countCharacters(words, chars);

    cout << "Result: " << result << endl;

    return 0;
}
