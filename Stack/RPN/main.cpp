#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


bool isNumber(string str) {
    for(char c : str) {
        if(!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int evalRPN(vector<string> tokens) {
    if(tokens.empty()) return 0;
    
    stack<int> stk;

    for(string str : tokens) {
        if(isNumber(str)) {
            stk.push(stoi(str));
            cout<<"pushed: "<<stoi(str)<<endl;
        }
        else {
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();
            int result = 0;
            char cstr = str[0];
            switch(cstr) {
                case '+':
                result = num1 + num2;
                break;

                case '-':
                result = num1 - num2;
                break;

                case '*':
                result = num1 * num2;
                break;

                case '/':
                result = static_cast<int>(static_cast<float>(num1) / static_cast<float>(num2));
                break;
            }

            stk.push(result);
            cout<<"pushed result: "<<result<<endl; 
        }
    }

    return stk.top();
}


int main() {
    int result = evalRPN({"1","2","+","3","*","4","-"});

    cout<<"result: "<<result<<endl;

    return 0;
}