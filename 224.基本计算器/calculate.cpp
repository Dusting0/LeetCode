#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
    bool isNum(char c) {
        return (c-'0'>=0 && c-'0'<=9) ? 1 : 0;
    }

    int calFromSuf(string suffix) {
        int n = suffix.length();
        stack<int> numStk;
        for(int i=0; i<n; i++) {
            if(isNum(suffix[i])){
                string num = "";
                while (suffix[i] != '|'){
                    num += suffix[i];
                    i++;
                }
                numStk.push(stoi(num));
            } else {
                int a = numStk.top(); numStk.pop();
                int b = numStk.top(); numStk.pop();
                int c = suffix[i]=='+' ? a+b : b-a;
                numStk.push(c);
            }
        }
        return numStk.top();
    }

public:
    stack<char> stk;

    int calculate(string s) {
        s = '0' + s;
        int n = s.length();
        string suffix = "";
        string singleNum = "";

        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                continue;
            }

            if(s[i] == '(') {
                stk.push(s[i]);

            } else if (s[i] == '+' || s[i] == '-') {
                if(stk.empty() || stk.top() == '(') {
                    stk.push(s[i]);
                } else {
                    suffix += stk.top(); stk.pop();
                    stk.push(s[i]);
                }
                
            } else if (s[i] == ')') {
                while(stk.top() != '(') {
                    suffix += stk.top();
                    stk.pop();
                }
                stk.pop();

            } else {
                string num = "";
                while (isNum(s[i])) {
                    num+=s[i];
                    i++;
                }
                num += '|';
                suffix += num;
                i--;
            }
        }

        while(!stk.empty()) {
            suffix += stk.top();
            stk.pop();
        }

        return calFromSuf(suffix);
    }
};

int main() {
    Solution solu;
    string s = "5-(4+5)+3";
    int re = solu.calculate(s);
    cout << re << endl;
}