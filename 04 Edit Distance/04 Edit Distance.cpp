// 04 Edit Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
	int m = word1.length() + 1;
	int n = word2.length() + 1;
	vector<vector<int>> d(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		d[i][0] = i;
	}
	for (int j = 0; j < n; j++) {
		d[0][j] = j;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				d[i][j] = d[i - 1][j - 1];
			} else {
				d[i][j] = 1 + min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1]));
			}
		}
	}
	return d[m - 1][n - 1];
}

int main()
{
	string word1 = "intention", word2 = "execution";
	int steps = minDistance(word1, word2);
	cout << steps << endl;
}