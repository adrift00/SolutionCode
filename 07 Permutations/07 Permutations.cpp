// 07 Permutations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void BackTrack(vector<int>& nums, int first, vector<vector<int>>& output) {
	if (first == nums.size() - 1) {
		output.push_back(nums);
	}
	for (int i = first; i < nums.size(); i++) {
		swap(nums[i], nums[first]);
		BackTrack(nums, first + 1, output);
		swap(nums[i], nums[first]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> output;
	BackTrack(nums, 0, output);
	return output;
}

int main() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result = permute(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
