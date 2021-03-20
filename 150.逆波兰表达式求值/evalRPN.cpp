#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0; i<tokens.size(); i++) {
            try {
                int num = stoi(tokens[i]);
                stk.push(num);
            } catch(std::invalid_argument) {
                string op = tokens[i];
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int c;
                if(op == "+") {
                    c = a + b;
                } else if(op == "-") {
                    c = b - a;
                } else if(op == "*") {
                    c = a * b;
                } else {
                    c = int(b / a);
                }
                stk.push(c);
            }
        }
        return stk.top();
    }
};

int main() {
    Solution solu;
    vector<string> tokens = {"4","13","5","/","+"};
    int re = solu.evalRPN(tokens);
    cout << re << endl;
}