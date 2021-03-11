#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution {
private:
    map<char, int> pri = {{'(', 0}, 
                          {'+', 1}, 
                          {'-', 1}, 
                          {'*', 2}, 
                          {'/', 2}};
    stack<char> stk;

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
                int c;
                switch (suffix[i])
                {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = b - a;
                    break;
                case '*':
                    c = a * b;
                    break;
                default:
                    c = int(b / a);
                    break;
                }
                numStk.push(c);
            }
        }
        return numStk.top();
    }

public:
    int calculate(string s) {
        s = '0' + s;
        int n = s.length();
        string suffix = "";
        string singleNum = "";

        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                continue;
            }

            if(isNum(s[i])) {
                string num = "";
                while (isNum(s[i])) {
                    num+=s[i];
                    i++;
                }
                num += '|';
                suffix += num;
                i--;
                continue;
            }

            if(s[i] == '(') {
                stk.push(s[i]);

            } else if (s[i] == ')') {
                while(stk.top() != '(') {
                    suffix += stk.top();
                    stk.pop();
                }
                stk.pop();

            } else {
                while(!stk.empty() && pri[stk.top()] >= pri[s[i]]) {
                    suffix += stk.top(); stk.pop();
                }
                stk.push(s[i]);
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
    string s = "1*2+5/2";
    int re = solu.calculate(s);
    cout << re << endl;
}