// 16 Coin Change.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
	vector<int> coins = { 1,2,5 };
	int amount = 11;
	cout << coinChange(coins, amount) << endl;
}


