// 28 Fence Repair.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long Solver1() {
	int N;
	cin >> N;
	vector<int> planks(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> planks[i];
	}
	long long totalCost = 0; //用int会溢出，因为题目的数据比较大
	if (N == 1) {
		return 0;
	}
	while (N > 1) {
		int idx1, idx2;
		planks[0] < planks[1] ? (idx1 = 0, idx2 = 1) : (idx1 = 1, idx2 = 0);
		for (int i = 2; i < N; i++) {
			if (planks[i] <= planks[idx1]) {
				idx2 = idx1;
				idx1 = i;
			} else if (planks[i] < planks[idx2]) {
				idx2 = i;
			}
		}
		int cost = planks[idx1] + planks[idx2];
		totalCost += cost;
		planks[idx1] = cost;
		planks[idx2] = planks[N - 1];
		N--;
	}
	return totalCost;
}
long long Solver2() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> planks;
	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		planks.push(num);
	}
	if (N == 1) {
		return 0;
	}
	long long totalCost = 0;
	while (N-- > 1) {
		int cost = 0;
		cost += planks.top();
		planks.pop();
		cost += planks.top();
		planks.pop();
		planks.push(cost);
		totalCost += cost;
	}
	return totalCost;

}

int main()
{
	cout << Solver1() << endl;
}
