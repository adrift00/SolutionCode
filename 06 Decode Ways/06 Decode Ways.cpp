// 06 Decode Ways.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int numDecodings(string s) {
	if (s[0] == '0') {
		return 0;
	}
	vector<int> numDec(s.length());
	numDec[0] = 1;
	int num = 0;
	for (int i = 1; i < s.length(); i++) {
		stringstream(s.substr(i - 1, 2)) >> num;
		if (num <= 26 && s[i - 1] != '0') {
			if (s[i] == '0') {
				numDec[i] = (i >= 2 ? numDec[i - 2] : numDec[i] = 1);
			} else {
				numDec[i] = (i >= 2 ? numDec[i - 1] + numDec[i - 2] : numDec[i] = numDec[i - 1] + 1);
			}
		} else {
			if (s[i] == '0') {
				return 0;
			} else {
				numDec[i] = numDec[i - 1];
			}
		}
	}
	return numDec[s.length() - 1];
}
int main() {
	string s = "106";
	cout << numDecodings(s) << endl;
}