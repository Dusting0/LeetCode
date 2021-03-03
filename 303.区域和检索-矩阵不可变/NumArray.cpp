#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    int l;
    vector<int> rowSum;
    NumArray(vector<int>& nums) {
        l = nums.size();
        rowSum.resize(l, 0);
        for(int i=l-1; i>=0; i--) {
            if(i == l-1) {
                rowSum[i] = nums[i];
            } else {
                rowSum[i] = nums[i] + rowSum[i+1];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(rowSum.empty()) {
            return 0;
        }
        if(j == l-1) {
            return rowSum[i];
        } else {
            return rowSum[i] - rowSum[j+1];
        }
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0, 2);
    cout << param_1 << endl;
}