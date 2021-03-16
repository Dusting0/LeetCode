#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<vector<int>> g(height, vector<int>(width, 0));
        vector<int> re;

        int layer = 0;
        int max_layer = int(min(height, width)/2) + 1;
        int m = width;
        int n = height;
        while(layer < max_layer) {
            for(int i=0; i<m; i++) {
                if(g[layer][i] != 1){
                    re.emplace_back(matrix[layer][i]);
                    g[layer][i] = 1;
                }
            }
            for(int j=1; j<n; j++) {
                if(g[layer+j][width-layer-1] != 1) {
                    re.emplace_back(matrix[layer+j][width-layer-1]);
                    g[layer+j][width-layer-1] = 1;
                }
            }
            for(int i=1; i<m; i++) {
                if(g[height-layer-1][width-i-1] != 1) {
                    re.emplace_back(matrix[height-layer-1][width-i-1]);
                    g[height-layer-1][width-i-1] = 1;
                }
            }
            for(int j=1; j<n-1; j++) {
                if(g[height-j-1][layer] != 1) {
                    re.emplace_back(matrix[height-j-1][layer]);
                    g[height-j-1][layer] = 1;
                }
            }
            m--;
            n--;
            layer++;
        }
        return re;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,0,1,2}};
    vector<int> re = solu.spiralOrder(matrix);
    for(int i=0; i<re.size(); i++) {
        cout << re[i] << " ";
    }
}