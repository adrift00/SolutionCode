// 26 Prime Path.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <cmath>
#include <chrono>
using namespace std;
int myCount = 0;
bool IsPrime(int num) {
	int sqrtNum = sqrt((float)num);
	for (int i = 2; i < sqrtNum; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
vector<int> CreatePrimeTable() {
	vector<int> primeTable(10001, 1);
	for (int i = 2; i < 100; i++) {
		if (primeTable[i] == 1) {
			for (int j = 2; i * j < 10001; j++) {
				//cout << i * j << endl;
				primeTable[i * j] = 0;
			}
		}
	}
	return primeTable;
}
vector<int> SplitNum(int num) {
	vector<int> nums(4, 0);
	nums[0] = num / 1000;
	nums[1] = (num % 1000) / 100;
	nums[2] = (num % 100) / 10;
	nums[3] = num % 10;
	return nums;
}
int CalcNum(vector<int> nums) { 
	return nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
}
int BFS(vector<int>& primeTable,int begin, int end) {
	vector<int> step(10000, 0);
	queue<int> q;
	q.push(begin);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num == end) {
			return step[end];
		}
		vector<int> oldNums = SplitNum(num);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (i == 3) {
					j++;
				}
				if (j == oldNums[i]) {
					continue;
				}
				vector<int> newNums = oldNums;
				newNums[i] = j;
				myCount++;
				int newNum = CalcNum(newNums);
				if (step[newNum] == 0 && primeTable[newNum] == 1) {
					q.push(newNum);
					step[newNum] = step[num] + 1;
					if (newNum == end) {
						return step[newNum];
					}
				}
			}
		}
	}
	return -1;
}
int VectorTest(vector<int> haha) {
	int sum = 0;
	for (int i = 0; i < haha.size(); i++) {
		haha[i] = i;
		sum += haha[i];
	}
	return sum;
}
int main()
{
	chrono::steady_clock::time_point start_time = chrono::steady_clock::now();//开始时间
	int N;
	cin >> N;
	vector<int> primeTable = CreatePrimeTable();
	while (N--) {
		int begin, end;
		cin >> begin >> end;
		int ret = BFS(primeTable, begin, end);
		if ( ret!=-1) {
			cout << ret << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	cout << myCount << endl;
	chrono::steady_clock::time_point stop_time = chrono::steady_clock::now();//结束时间
	chrono::duration<double> time_span = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
	std::cout << "共耗时：" << time_span.count() << " ms" << endl; // 耗时

	//chrono::steady_clock::time_point start_time = chrono::steady_clock::now();//开始时间
	//vector<int> haha(4, 0);
	//int sum = 0;
	//for (int i = 0; i < 2649850; i++) {
	//	sum = VectorTest(haha);
	//}
	//chrono::steady_clock::time_point stop_time = chrono::steady_clock::now();//结束时间
	//chrono::duration<double> time_span = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
	//std::cout << "共耗时：" << time_span.count() << " ms" << endl; // 耗时

}
