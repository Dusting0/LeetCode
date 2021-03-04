#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] > e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        int re = 0;
        vector<int> dp(envelopes.size(), 1);
        for(int i=envelopes.size()-1; i>=0; i--) {
            for(int j=i+1; j<envelopes.size(); j++) {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            re = max(re, dp[i]);
        }
        return re;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> envelopes = {{1,2},{2,3},{3,4},{3,5},{4,5},{5,5},{5,6},{6,7},{7,8}};
    int re = solu.maxEnvelopes(envelopes);
    cout << re << endl;
}