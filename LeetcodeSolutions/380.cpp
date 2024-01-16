#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>idxMap;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idxMap.find(val)!=idxMap.end()){
            return false;
        }
        nums.push_back(val);
        idxMap[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(idxMap.find(val)==idxMap.end()){
            return false;
        }
        int last=nums.back();
        idxMap[last]=idxMap[val];
        nums[idxMap[last]]=last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};
int main() {
    RandomizedSet* obj = new RandomizedSet();

    // Sample input
    vector<string> operations = {"insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"};
    vector<vector<int>> values = {{1}, {2}, {2}, {}, {1}, {2}, {}};

    vector<int> output;

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "insert") {
            bool param = obj->insert(values[i][0]);
            output.push_back(param ? true : false);
        } else if (operations[i] == "remove") {
            bool param = obj->remove(values[i][0]);
            output.push_back(param ? true : false);
        } else if (operations[i] == "getRandom") {
            int param = obj->getRandom();
            output.push_back(param);
        }
    }

    // Displaying the output
    cout << "Output: [";
    for (int i = 0; i < output.size(); ++i) {
        if (i > 0) cout << ",";
        if (output[i] == true || output[i] == false) {
            cout << (output[i] ? "true" : "false");
        } else {
            cout << output[i];
        }
    }
    cout << "]" << endl;

    delete obj;
    return 0;
}