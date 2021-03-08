#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> judge(n, vector<int>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                judge[i][j] = (s[i] == s[j]) && judge[i + 1][j - 1];
            }
        }

        vector<int> dp(n, 2001);
        for(int i=0; i<n; i++) {
            if(judge[0][i]) {
                dp[i] = 0;
                continue;
            }
            for(int j=i-1; j>=0; j--) {
                if(judge[j+1][i]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution solu;
    string s = "aabcaa";
    int re = solu.minCut(s);
    cout << re << endl;
}