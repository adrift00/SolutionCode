// Missing number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;
void DFS(string str, int index,vector<int> splitNum,int num,int n)
{
	if (index == str.length())
	{
		set<int> uniqueNum(splitNum.begin(),splitNum.begin()+num);//转化为set
		//for (auto it = uniqueNum.begin(); it!=uniqueNum.end(); it++)
		//{
		//	cout << *it << ' ';
		//}
		//cout << endl;
		if (uniqueNum.size() != n - 1)
		{
			return;
		}
		for (int i = 1; i < n + 1; i++)
		{
			set<int>::iterator it = uniqueNum.find(i);
			if (it == uniqueNum.end())
			{
				cout << i << endl;
				return;
			}
		}
	}
	else
	{
		if (num > n - 1)
		{
			return;
		}
		if (str[index] == '0')
		{
			return;
		}
		int curNum = 0;
		stringstream ss(str.substr(index,1));
		ss >> curNum;
		if (curNum > n)
			return;
		splitNum[num] = curNum;
		DFS(str, index + 1, splitNum, num + 1, n);
		if (index != str.length() - 1)
		{
			stringstream ss(str.substr(index, 2));
			ss >> curNum;
			if (curNum > n)
				return;
			splitNum[num] = curNum;
			DFS(str, index + 2, splitNum, num + 1, n);
		}
	}

}
int main()
{
	int n = 27;
	string str("3725816181026271711142021232413191295615224");
	int num = 0;
	int index = 0;
	vector<int> splitNum(str.length());
	DFS(str, index, splitNum, num, n);
}