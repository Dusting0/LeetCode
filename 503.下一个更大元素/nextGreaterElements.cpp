#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> re(n, -1);
        stack<int> s;
        for (int i=0; i<2*n; i++) {
            if(s.empty() || nums[i % n] <= nums[s.top()]) {
                s.push(i % n);
            } else {
                while(!s.empty() && nums[i % n] > nums[s.top()]) {
                    re[s.top()] = nums[i % n];
                    s.pop();
                }
                s.push(i % n);
            }
        }
        return re;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1, 2, 1};
    vector<int> re = solu.nextGreaterElements(nums);
    for(int i=0; i<re.size(); i++) {
        cout << re[i] << endl;
    }
}