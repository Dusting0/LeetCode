#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = 0;
        int curPos = 0;
        int nextPos = 0;
        int maxDist = 0;
        
        if(nums[0]>=nums.size()-1) return true;
        while(curPos != nums.size()-1) {
            lastPos = curPos;
            nextPos = curPos;
            maxDist = 0;
            for(int i=1; i<=nums[curPos]; i++) {
                if(i+nums[curPos+i] >= maxDist) {
                    nextPos = curPos + i;
                    maxDist = nums[curPos+i] + i;
                }
            }
            curPos = nextPos;
            if(curPos + nums[curPos] >= nums.size()-1) return true;
            if(lastPos == curPos) return false;
        }
        return true;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {16,0};
    cout << solu.canJump(nums) << endl;
}