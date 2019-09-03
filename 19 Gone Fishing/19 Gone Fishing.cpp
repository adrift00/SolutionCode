// 19 Gone Fishing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0, h = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cin >> h;
		h = h * 12;
		vector<int> fi(n);
		vector<int> di(n);
		vector<int> ti(n - 1);
		for (int i = 0; i < n; i++) {
			cin >> fi[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> di[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> ti[i];
		}
		vector<int> t(n); //计算到每个湖的时间
		for (int i = 0; i < n - 1; i++) {
			t[i + 1] = t[i] + ti[i];
		}
		vector<int> spendTime(n);//每个湖花费的时间
		int totalFish = 0;
		for (int i = 0; i < n; i++) {
			int leaveTime = h;
			leaveTime -= t[i];
			vector<int> tmpfi = fi;
			vector<int> tmpSpendTime(n,0);
			int tmpTotalFish = 0;
			while (leaveTime > 0) {
				int maxfi = 0, maxIdx = 0;
				for (int j = 0; j <= i; j++) {
					if (tmpfi[j] > maxfi) {
						maxfi = tmpfi[j];
						maxIdx = j;
					}
				}
				tmpSpendTime[maxIdx] += 1;
				leaveTime--;
				tmpTotalFish += tmpfi[maxIdx];
				tmpfi[maxIdx] -= di[maxIdx];
				tmpfi[maxIdx] = (tmpfi[maxIdx] > 0 ? tmpfi[maxIdx] : 0);
				int isEmpty = 0;
				for (int j = 0; j < n; j++) {
					if (tmpfi[j] > 0) {
						isEmpty++;
					}
				}
				if (isEmpty == 0) {
					tmpSpendTime[0] += leaveTime;
					break;
				}
			}
			if (tmpTotalFish > totalFish) {
				totalFish = tmpTotalFish;
				spendTime = tmpSpendTime;
			}
		}
		
		for (int i = 0; i < n-1; i++) {
			cout << spendTime[i]*5<<", " ;
		}
		cout << spendTime[n - 1] * 5;
		cout << endl;
		cout << "Number of fish expected: "  << totalFish << endl;
		cout << endl;
	}
}
