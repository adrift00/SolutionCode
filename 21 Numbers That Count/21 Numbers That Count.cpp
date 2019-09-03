// 21 Numbers That Count.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string Transform(string s) {
	vector<int> numcount(10, 0);
	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - '0';
		numcount[index]++;
	}
	string newstr;
	for (int i = 0; i < numcount.size(); i++) {
		if (numcount[i] != 0) {
			newstr.append(to_string(numcount[i]));
			newstr.append(to_string(i));
		}
	}
	return newstr;
}
int main()
{
	string inputstr;
	while (cin >> inputstr && inputstr[0] != '-') {
		string curstr = inputstr;
		vector<string> hisStr(16);
		hisStr[0]=inputstr;
		for (int iter = 1; iter <= 16; iter++) {
			if (iter == 16) {
				cout << inputstr << " " << "can not be classified after 15 iterations" << endl;
				break;
			}
			string newstr=Transform(curstr);
			hisStr[iter] = newstr;
			if (newstr == curstr&&iter==1) {
				cout << inputstr << ' ' << "is self-inventorying" << endl;
				break;
			}else if (newstr == curstr && iter > 1) {
				cout << inputstr << ' ' << "is self-inventorying after " << iter-1 << " steps" << endl;
				break;
			}else{
				bool isLoop = false;
				for (int i = 0; i < iter; i++) {
					if (hisStr[iter] == hisStr[i]) {
						cout << inputstr << " " << "enters an inventory loop of length " << iter-i << endl;
						isLoop = true;
						break;
					}
				}
				if (isLoop == true) {
					break;
				}
			}
			curstr = newstr;
		}
		
	}
}