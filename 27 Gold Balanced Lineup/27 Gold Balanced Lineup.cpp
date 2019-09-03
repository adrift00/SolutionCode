// 27 Gold Balanced Lineup.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAXN 100000
int sum[MAXN + 1][30] = { 0 };
int c[MAXN + 1][30];
int sumC[MAXN + 1] = { 0 };
int main()
{
	int num, numbits;
	cin >> num >> numbits;
	//用vector会超时，所以使用全局数组
	//vector<vector<int> > sum(num + 1, vector<int>(numbits, 0));
	//vector<vector<int> > c(num + 1, vector<int>(numbits, 0));
	//vector<int> sumC(num + 1, 0);
	vector<vector<int> > hash(num + 1, vector<int>());
	int maxlen = 0;
	for (int i = 1; i <= num; i++) {
		int decNum;
		cin >> decNum;
		vector<int> binNums(numbits, 0);
		for (int i = 0; i < numbits; i++) {
			binNums[numbits - i - 1] = decNum % 2;
			decNum /= 2;
		}
		for (int j = 0; j < numbits; j++) {
			sum[i][j] = sum[i - 1][j] + binNums[j];
			c[i][j] = sum[i][j] - sum[i][0];
			sumC[i] += c[i][j];
		}
	}
	for (int i = 0; i <= num; i++) {
		int key = abs(sumC[i]) % num;
		for (int j = 0; j < hash[key].size(); j++) {
			int lastIdx = hash[key][j];
			int isEqual = true;
			for (int k = 0; k < numbits; k++) {
				if (c[i][k] != c[lastIdx][k]) {
					isEqual = false;
					break;
				}
			}
			if (isEqual == true && (i - lastIdx  > maxlen)) {
				maxlen = i - lastIdx ;
			}
		}
		hash[key].push_back(i);
	}
	cout << maxlen << endl;
}