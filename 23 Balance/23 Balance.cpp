// 23 Balance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int C, G;
	cin >> C >> G;
	vector<int> hook(C);
	vector<int> weight(G + 1);
	for (int i = 0; i < C; i++) {
		cin >> hook[i];
	}
	for (int i = 1; i <= G; i++) {
		cin >> weight[i];
	}
	int end = G * 25 * 15 * 2;
	int mid = G * 25 * 15;
	vector<vector<int>> dp(G + 1, vector<int>(end + 1, 0));
	dp[0][mid] = 1;
	for (int i = 1; i <= G; i++) {
		for (int j = 0; j <= end; j++) {
			for (int k = 0; k < C; k++) {
				if (dp[i - 1][j] != 0) {
					dp[i][j + hook[k] * weight[i]] += dp[i - 1][j];
				}

			}
		}
	}
	cout << dp[G][mid] << endl;
}



