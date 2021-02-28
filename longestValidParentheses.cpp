#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <sys/types.h>


using namespace std;

int main() {
	int stack = 0;
	int former_length = 0;
	int lr_max_length = 0;
	int rl_max_length = 0;
	int cur_length = 0;
	string s = "(()";

	// 从左往右
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') stack += 1;
		else {
			if (stack == 0) {
				former_length = 0; // 不再连贯
			}
			else if (stack == 1) { // 匹配后栈空
				stack -= 1;
				cur_length += 2;
				
				former_length += cur_length; // 区段合并

				lr_max_length = max(lr_max_length, former_length);
				cur_length = 0;	// 当前区段结束
			}
			else {
				stack -= 1;
				cur_length += 2;
			}
		}
	}

	stack = 0;
	cur_length = 0;
	former_length = 0;
	//从右往左
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == ')') stack += 1;
		else {
			if (stack == 0) {
				former_length = 0;
			}
			else if (stack == 1) {
				stack -= 1;
				cur_length += 2;

				former_length += cur_length;

				rl_max_length = max(rl_max_length, former_length);
				cur_length = 0;
			}
			else {
				stack -= 1;
				cur_length += 2;
			}
		}
	}

	cout << "lr max:" << lr_max_length << endl;
	cout << "rl max:" << rl_max_length << endl;
	int true_length = max(lr_max_length, rl_max_length);
	cout << "true max:" << true_length << endl;

}


