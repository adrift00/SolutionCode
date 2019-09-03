// 24 Cash Machine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int cash = 0;
	while (cin>> cash&&cash!=EOF) {
		int  N = 0;
		cin >> N;
		vector<int> dp(cash+1, 0);
		int num, value;
		for (int i = 0; i < N; i++) {
			cin >> num >> value;
			int k = 1;
			while (k < num) {
				//01背包
				for (int c = cash; c >= k * value; c--) {
					dp[c] = max(dp[c], dp[c - k * value] + k * value);
				}
				num -= k;
				k *= 2;
			}
			//对剩余的进行01背包
			for (int c = cash; c >= num * value; c--) {
				dp[c] = max(dp[c], dp[c - num * value] + num * value);
			}
		}
		int maxcash = 0;
		for (int i = 0; i <= cash; i++) {
			maxcash = max(dp[i], maxcash);
		}
		cout << maxcash << endl;
	}
}
