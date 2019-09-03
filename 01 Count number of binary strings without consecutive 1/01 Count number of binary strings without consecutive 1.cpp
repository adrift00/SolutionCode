// 01 Count number of binary strings without consecutive 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int num = 0;
int dfs(int deep, int bit, int lastbit, int n)
{

	if (lastbit == 1 && bit == 1)
	{
		return 0;
	}
	if (deep == n)
	{
		num++;
		return 0;
	}
	dfs(deep + 1, 0, bit, n);
	dfs(deep + 1, 1, bit, n);
}
int dp(int n)
{
	int* a = new int[n + 1]{ 0,2,3 };
	for (int i = 3; i < n + 1; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}
int main()
{
	int n = 6;
	cout << dp(n) << endl;
	dfs(1, 0, 0, n);
	dfs(1, 1, 0, n);
	cout << num << endl;
}

