#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    int m, n;
    vector<vector<int>> rowSum; 
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            m = 0;
            n = 0;
            return;
        }
        m = matrix.size();
        n = matrix[0].size();
        rowSum.resize(m, vector<int>(n));

        for(int i=0; i<m; i++) {
            for(int j=n-1; j>=0; j--) {
                if(j == n-1) {
                    rowSum[i][j] = matrix[i][j];
                } else {
                    rowSum[i][j] = matrix[i][j] + rowSum[i][j+1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1; i<=row2; i++) {
            if(col2 == n-1) {
                sum += rowSum[i][col1];
            } else {
                sum += rowSum[i][col1] - rowSum[i][col2+1];
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, 
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2, 1, 4, 3);
    cout << param_1 << endl;
    param_1 = obj->sumRegion(1, 1, 2, 2);
    cout << param_1 << endl;
    param_1 = obj->sumRegion(1, 2, 2, 4);
    cout << param_1 << endl;
}