#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

// Function to check if the given character is an operator (+, -, *, /, ^)
bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}

// Function to get the precedence of an operator
int getPrecedence(string op) {
    if (op == "+" || op == "-")
        return 1;
    else if (op == "*" || op == "/")
        return 2;
    else if (op == "^")
        return 3;
    return 0;
}

// Function to perform arithmetic operations
int performOperation(int a, int b, string op) {
        if(op=="+")
            return a + b;
        else if(op=="-")
            return a - b;
        else if(op=="*")
            return a * b;
        else if(op=="/")
            return a / b;
        else if(op=="^")
            return pow(a, b);
        else
            return 0;
    }


// Function to evaluate the infix expression recursively
int evaluateInfix(string s[], int start, int end) {
    if (start == end) {
        // Base case: when only one element is left (an operand)
        return stoi(s[start]);
    }

    int opIndex = -1; // Index to store the operator with the highest precedence
    int minPrecedence = 4;

    // Find the operator with the highest precedence
    for (int i = start; i <= end; i++) {
        if (isOperator(s[i])) {
            int precedence = getPrecedence(s[i]);
            if (precedence <= minPrecedence) {
                minPrecedence = precedence;
                opIndex = i;
            }
        }
    }

    // Split the expression at the operator with the highest precedence
    int leftOperand = evaluateInfix(s, start, opIndex - 1);
    int rightOperand = evaluateInfix(s, opIndex + 1, end);

    // Perform the operation and return the result
    return performOperation(leftOperand, rightOperand, s[opIndex]);
}

int main() {
    cout << "Enter the string" << endl;
    string str;
    cin >> str;
    int c = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
            c++;
    }
    int d = 2 * c + 1;
    string s[d] = {};
    int t = 0;
    int j = 0;
    int q = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^')
            q++;
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            s[j] = str.substr(t, q);
            q = 0;
            j++;
            t = i + 1;
            s[j] = str.substr(i, 1);
            j++;
        }
    }
    s[j] = str.substr(t);

    // Evaluate the infix expression recursively
    int finalResult = evaluateInfix(s, 0, d - 1);
    cout << "The result is: " << finalResult << endl;
}
