// 09 ZigZag Conversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	int len = min(int(s.length()), numRows);
	vector<vector<char>> vec(len);
	int direction = 1, row = 0;
	for (int i = 0; i < s.length(); i++) {
		vec[row].push_back(s[i]);
		if (row == 0) direction = 1;
		if (row == numRows - 1)direction = 0;
		if (direction == 1) {
			row++;
		} else {
			row--;
		}
	}
	string ret;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			ret.push_back(vec[i][j]);
		}
	}
	return ret;
}

int main()
{
	string s = "AB";
	string ret = convert(s, 1);
	cout << ret << endl;
}
