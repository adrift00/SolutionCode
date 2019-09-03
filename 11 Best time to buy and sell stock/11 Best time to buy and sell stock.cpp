// 11 Best time to buy and sell stock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int maxProfit(vector<int>& prices) {
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			int profit = prices[j] - prices[i];
			if (profit > maxProfit) {
				maxProfit = profit;
			}
		}
	}
	return maxProfit;
}
int maxProfit2(vector<int>& prices) {
	int minPrice = numeric_limits<int>::max();
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < minPrice) {
			minPrice = prices[i];
		}
		if (prices[i] - minPrice > maxProfit) {
			maxProfit = prices[i] - minPrice;
		}
	}
	return maxProfit;
}


int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << maxProfit2(prices) << endl;
}
