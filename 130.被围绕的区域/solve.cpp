#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        stack<vector<int>> stk;

        set<int> live_block;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // 跳过非边界
                if(i!=0 && i!=m-1) {
                    if(j!=0 && j!=n-1) {
                        continue;
                    }
                }

                if(board[i][j] == 'O') {
                    vector<int> co = {i, j};
                    stk.push(co);
                    while(!stk.empty()) {
                        co = stk.top(); stk.pop();
                        int x = co[0], y=co[1];
                        board[x][y] = 'F';

                        // UP, LEFT, DOWN, RIGHT
                        if(x != 0 && board[x-1][y] == 'O') {
                            co = {x-1, y};
                            stk.push(co);
                        }
                        if(y != 0 && board[x][y-1] == 'O') {
                            co = {x, y-1};
                            stk.push(co);
                        }
                        if(x != m-1 && board[x+1][y] == 'O') {
                            co = {x+1, y};
                            stk.push(co);
                        }
                        if(y != n-1 && board[x][y+1] == 'O') {
                            co = {x, y+1};
                            stk.push(co);
                        }
                    }
                }
            }    
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    Solution solu;
    vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    solu.solve(board);
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    } 
}