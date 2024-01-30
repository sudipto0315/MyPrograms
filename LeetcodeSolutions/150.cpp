#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool isOperator(string st){
        if(st=="+"||st=="-"||st=="*"||st=="/"){
            return true;
        }else{
            return false;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(isOperator(tokens[i])==true){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                int val;
                if(tokens[i]=="+"){
                    val=num1+num2;
                }else if(tokens[i]=="-"){
                    val=num1-num2;
                }else if(tokens[i]=="*"){
                    val=num1*num2;
                }else if(tokens[i]=="/"){
                    val=num1/num2;
                }
                st.push(val);
            }else{
                int num=stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
int main(){
    Solution s;
    vector<string>tokens={"2","1","+","3","*"};
    cout<<s.evalRPN(tokens)<<endl;
    tokens={"4","13","5","/","+"};
    cout<<s.evalRPN(tokens)<<endl;
    tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<s.evalRPN(tokens)<<endl;
    return 0;
}