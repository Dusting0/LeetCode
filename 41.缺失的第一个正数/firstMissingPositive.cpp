#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int _=0; _<n; _++) {
            for(int i=0; i<n; i++){
                if(nums[i] <= 0 || nums[i] > n) {
                    continue;
                }
                if(nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1,2,0};
    int re = solu.firstMissingPositive(nums);
    cout << re << endl;
}