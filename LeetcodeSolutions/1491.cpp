#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(salary[i]>max){
                max=salary[i];
            }
            if(salary[i]<min){
                min=salary[i];
            }
        }
        cout<<max<<" "<<min<<endl;
        double avg=0.00000;
        double count=0;
        double sum=0;
        for(int i=0;i<n;i++){
            if(salary[i]!=min && salary[i]!=max)
            {
                sum+=salary[i];
                count++;
            }
        }
        cout<<sum<<endl;
        cout<<count<<endl;
        avg=sum/count;
        return avg;
    }
};
int main(){
    Solution s;
    vector<int> v={4000,3000,1000,2000};
    cout<<s.average(v)<<endl;
    v={1000,2000,3000};
    cout<<s.average(v)<<endl;
    v={6000,5000,4000,3000,2000,1000};
    cout<<s.average(v)<<endl;
    return 0;
}