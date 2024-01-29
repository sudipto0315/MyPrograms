#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {

    }

    void push(int x) {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
        while (!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int top=stack1.top();
        stack1.pop();
        return top;
    }

    int peek() {
        return stack1.top();
    }

    bool empty() {
        return stack1.empty();
    }
};
int main(){
    MyQueue* obj = new MyQueue();
    int x = 5; // Define x before using it
    obj->push(x);
    if (!obj->empty()) {
        int param_2 = obj->pop();
        cout << "Pop operation result: " << param_2 << endl;
    }
    if (!obj->empty()) {
        int param_3 = obj->peek();
        cout << "Peek operation result: " << param_3 << endl;
    }
    bool param_4 = obj->empty();
    cout << "Empty operation result: " << (param_4 ? "Queue is empty" : "Queue is not empty") << endl;
    delete obj;
    return 0;
}