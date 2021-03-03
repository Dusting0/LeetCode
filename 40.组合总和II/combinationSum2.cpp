#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> p_candidates, single_candidate;
    vector<vector<int>> re;
    int p_target;
    void DFS(int start_subscript, int sum, int cnt) {
        if(sum == p_target) {
            re.emplace_back(single_candidate);
            return;
        }

        for(int i=start_subscript; i<p_candidates.size(); i++) {
            if(i>start_subscript && p_candidates[i] == p_candidates[i-1]) {
                continue;
            }
            if(p_candidates[i] != p_target - sum) {
                if(p_candidates[i] + sum > p_target) {
                    return;
                }
                if(2 * p_candidates[i] > p_target - sum) { //由于后面的元素都比当前元素大，则继续遍历也不可能找到合理值
                    continue;
                }
            }
            
            single_candidate.emplace_back(p_candidates[i]);
            DFS(i+1, sum + p_candidates[i], cnt+1);
            single_candidate.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        p_candidates = candidates;
        p_target = target;
        DFS(0, 0, 0);
        return re;
    }
};

int main() {
    Solution solu;
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> re = solu.combinationSum2(candidates, target);
    for(int i=0; i<re.size(); i++) {
        cout << '[';
        for(int j=0; j<re[i].size(); j++) {
            cout << re[i][j] << " ";
        }
        cout << ']' << endl;
    }
}