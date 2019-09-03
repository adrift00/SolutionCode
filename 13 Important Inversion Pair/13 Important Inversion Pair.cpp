// 13 Important Inversion Pair.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
long long InversionPairCount(vector<long long>& nums) {
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] > 2 * nums[j]) {
				count++;
			}
		}
	}
	return count;
}




int main()
{
	vector<long long> nums = { 0 ,9 ,8 ,7 ,6, 5 ,4, 3, 2, 1 };
	cout << InversionPairCount(nums) << endl;
}


