#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        bool flag = true;
        while(flag) {
            flag = false;
            string::iterator it = S.begin()+1;
            while(it <= S.end()) {
                if(*it == *(it-1)) {
                    S.erase(it);
                    S.erase(it-1);
                    flag = true;
                }
                it++;
            }
        }
        return S;
    }
};

int main() {
    Solution solu;
    string S = "";
    string re = solu.removeDuplicates(S);
    cout << re << endl;
}