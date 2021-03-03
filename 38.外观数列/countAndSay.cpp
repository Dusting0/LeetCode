#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string countAndSay(int n) {
        string lastStr = "1";
        if(n==1) return lastStr;

        for(int _=2; _<=n; _++) {
            int cnt = 0;
            string curStr = "";
            for(int i=0; i<lastStr.length(); i++){
                if(i==0 || lastStr[i] == lastStr[i-1]) {
                    cnt += 1;
                }
                else {
                    curStr += to_string(cnt) + lastStr[i-1];
                    cnt = 1;
                }
            }
            curStr += to_string(cnt) + lastStr[int(lastStr.length())-1];
            lastStr = curStr;
        }
        return lastStr;
    }

};

int main() {
    Solution solu;
    for(int i=1; i<=30; i++){
        string s = solu.countAndSay(i);
        cout << s << endl; 
    }
    
}
