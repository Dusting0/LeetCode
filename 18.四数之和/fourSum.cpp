#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cxxabi.h>
using namespace std;


class Solution{
private:
    vector<vector<int>> re;
    vector<int> p_nums, single_solution;
    int p_target;
    void DFS(int start_subscript, int sum) {
        if(single_solution.size() == 4 && sum == p_target) {    //递归退出条件
            re.emplace_back(single_solution);
            return;
        }

        for(int i=start_subscript; i<p_nums.size(); i++) {
            
            if(p_nums.size() - i < 4 - single_solution.size()) return;

            if(i > start_subscript && p_nums[i] == p_nums[i-1])  continue;
            
            if(i < p_nums.size() - 1 && sum + p_nums[i] + int(3 - single_solution.size()) * p_nums[i+1] > p_target) return;
            
            if(i < p_nums.size() - 1 && sum + p_nums[i] + int(3 - single_solution.size()) * p_nums[p_nums.size()-1] < p_target) continue;
            
            single_solution.emplace_back(p_nums[i]);
            DFS(i+1, sum + p_nums[i]);
            single_solution.pop_back();
        }
        return;
    }    


public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        p_nums = nums;
        p_target = target;
        DFS(0,0);
        return re;
    }

};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution s;
    vector<vector<int>> re;
    re = s.fourSum(nums, target);
    for(int i=0; i<re.size(); i++) {
        for(int j=0; j<4; j++) {
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }

}