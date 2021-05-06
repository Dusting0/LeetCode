#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void reSort(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++; end--;
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return;
        int i;
        for(i=(int)nums.size()-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                for(int j=(int)nums.size()-1; j>i; j--) {
                    if(nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                i++;
                break;
            }
        }
        i = i<0 ? 0 : i;
        reSort(nums, i, (int)nums.size()-1);
    }
};

int main() {
    Solution solu;
    vector<int> nums = {3,2,1};
    solu.nextPermutation(nums);
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

// 1,4,9,7,3,1
// 1,7,9,4,3,1
// 1,7,1,3,4,9