#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> re;
    int fill(int layer, int size, int start_element) {
        int cnt = start_element;
        for(int i=layer; i<layer+size; i++) {
            re[layer][i] = cnt;
            cnt += 1;
        }
        for(int j=layer+1; j<layer+size; j++) {
            re[j][layer+size-1] = cnt;
            cnt += 1;
        }
        for(int i=layer+size-2; i>=layer; i--) {
            re[layer+size-1][i] = cnt;
            cnt += 1;
        }
        for(int j=layer+size-2; j>layer; j--) {
            re[j][layer] = cnt;
            cnt += 1;
        }
        return cnt;
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        re.resize(n, vector<int>(n, 0));
        int next_element = 1;
        for(int i=0; i<int(n/2.0+0.5); i++) {
            next_element = fill(i, n-2*i, next_element);
        }
        return re;
    }
};
 
int main() {
    Solution solu;
    vector<vector<int>> re = solu.generateMatrix(5);
    for(int i=0; i<re.size(); i++) {
        for(int j=0; j<re[i].size(); j++) {
            cout << re[i][j] << "\t";
        }
        cout << endl;
    }
}