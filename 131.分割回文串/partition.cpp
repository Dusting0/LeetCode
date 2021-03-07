#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> re;
    vector<string> subAns;

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }

    void DFS(int start_subscript, int n, string s) {
        if(start_subscript >= n) {
            re.emplace_back(subAns);
            return;
        }

        for(int i=start_subscript+1; i<=n; i++) {
            if(isPalindrome(s.substr(start_subscript, i-start_subscript))) {
                subAns.emplace_back(s.substr(start_subscript, i-start_subscript));
                DFS(i, n, s);
                subAns.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        DFS(0, n, s);
        return re;
    }
};

int main() {
    Solution solu;
    string s = "aab";
    vector<vector<string>> re = solu.partition(s);
    for(int i=0; i<re.size(); i++) {
        for(int j=0; j<re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << endl;
    }
}
