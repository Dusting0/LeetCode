#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPowOf2(int n) {
        if(!n) return false;
        while(n!=1) {
            if(n & 1) {
                return false;
            }
            n >>= 1;
        }
        return true;
    }

public:
    vector<int> countBits(int num) {
        vector<int> re(num+1, 0);
        int dist = 1;
        if(!num) {
            return re;
        }

        for(int i=1; i<=num; i++) {
            if(isPowOf2(i)) {
                re[i] = 1;
                dist = i;
                continue;
            }
            re[i] = 1 + re[i-dist];
        }
        return re;
    }
};

int main() {
    Solution solu;
    vector<int> re = solu.countBits(20);
    for(int i=0; i<re.size(); i++) {
        cout << i << "\t"; 
    }
    cout << endl;
    for(int i=0; i<re.size(); i++) {
        cout << re[i] << "\t";
    }
}
