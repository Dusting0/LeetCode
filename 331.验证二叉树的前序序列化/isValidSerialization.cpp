#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> nodes;
    void split(string s) {
        string tmp;
        for(int i=0; i<s.length(); i++) {
            if(s[i]==',') {
                nodes.emplace_back(tmp);
                tmp = "";
            } else {
                tmp += s[i];
            } 
        }
        nodes.emplace_back(tmp);
    }

public:
    bool isValidSerialization(string preorder) {
        split(preorder);
        int empty_node=1;
        for(int i=0; i<nodes.size(); i++) {
            if(!empty_node) return false;

            if(nodes[i] == "#") {
                empty_node--;
            } else {
                empty_node++;
            }
        }
        return empty_node == 0;
    }
};

int main() {
    Solution solu;
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool re = solu.isValidSerialization(s);
    cout << re;
}