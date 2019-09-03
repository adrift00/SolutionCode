// 12 Memorable Telephone Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void TelephoneCount(vector<string>& tel) {
	vector<string> finalTel;
	vector<int> telCount;
	map<char, char> table = { {'A','2'},{'B','2'},{'C','2'},{'D','3'} ,{'E','3'},{'F','3'},{'G','4'} ,{'H','4'} ,{'I','4'},
					{'J','5'}, {'K','5'}, {'L','5'}, {'M','6'}, {'N','6'}, {'O','6'}, {'P','7'}, {'R','7'}, {'S','7'} ,
					{'T','8'} ,{'U','8'}, {'V','8'}, {'W','9'}, {'X','9'}, {'Y','9'} };
	for (int i = 0; i < tel.size(); i++) {
		tel[i].erase(remove(tel[i].begin(), tel[i].end(), '-'), tel[i].end());
		for (int j = 0; j < tel[i].size(); j++) {
			if (tel[i][j] >= 'A' && tel[i][j] <= 'Z') {
				tel[i][j] = table[tel[i][j]];
			}
		}
	}
	sort(tel.begin(), tel.end());
	int count = 1;
	for (int i = 0; i < tel.size(); i++) {
		while (tel[i] == tel[i + 1]) {
			i++;
			count++;
		}
		if (count >= 2) {
			finalTel.push_back(tel[i]);
			telCount.push_back(count);
		}
		i++;
		count = 1;
	}
	return;
}
int main() {
	vector<string> tel = { "4873279",
						"ITS-EASY",
						"888-4567",
						"3-10-10-10",
						"888-GLOP",
						"TUT-GLOP",
						"967-11-11",
						"310-GINO",
						"888-1200",
						"F101010",
						"-4-8-7-3-2-7-9-",
						"487-3279" };
	TelephoneCount(tel);
}


