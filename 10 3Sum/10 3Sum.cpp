// 10 3Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsEqualVector(vector<int> v1, vector<int> v2) {
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	return v1 == v2;
}
void DFS(vector<vector<int>>& sol, vector<int>& vec,vector<int>& nums, int idx,int num,int sum) {
	for (int i = idx; i < nums.size(); i++) {
		sum += nums[i];
		vec.push_back(nums[i]);
		if (num == 3 && sum == 0) {
			for (int j = 0; j < sol.size(); j++) {
				if (IsEqualVector(sol[j], vec)) {
					sum -= nums[i];
					vec.pop_back();
					return;
				}
			}
			sol.push_back(vec);
			sum -= nums[i];
			vec.pop_back();
			return;
		}
		if (num == 3 && sum != 0) {
			sum -= nums[i];
			vec.pop_back();
			continue;
		}
		DFS(sol,vec,nums, i + 1, num + 1, sum);
		sum -= nums[i];
		vec.pop_back();
	}
}
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> sol;
	vector<int> vec;
	DFS(sol, vec, nums, 0, 1, 0);
	return sol;
}
//DFS会超时，下面是较好解法，而且根本不要用递归，三层循环足够了
vector<vector<int>> threeSum2(vector<int>& nums) {
	vector<vector<int>> ret;
	if (nums.size() < 3) {  //注意点1
		return {};
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-2; i++) {
		if (nums[i] > 0) { //2
			break;
		}
		if (i >= 1 && nums[i] == nums[i - 1]) {//3
			continue;
		}
		int l = i + 1, r = int(nums.size()) - 1;
		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			if ( sum== 0) {
				ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
				while (l<r&&nums[l] == nums[l + 1]) l++; //&&短路特性
				while (l<r&&nums[r] == nums[r - 1]) r--;
				if (l < r) {
					l++;
					r--;
				}
			} else if (sum < 0) {
				l++;
			} else if (sum > 0) {
				r--;
			}
		}
	}
	return ret;
}
int main()
{
	vector<int> nums = { 12,5,-12,4,-11,11,2,7,2,-5,-14,-3,-3,3,2,-10,9,-15,2,14,-3,-15,-3,-14,-1,-7,11,-4,-11,12,-15,-14,2,10,-2,-1,6,7,13,-15,-13,6,-10,-9,-14,7,-12,3,-1,5,2,11,6,14,12,-10,14,0,-7,11,-10,-7,4,-1,-12,-13,13,1,9,3,1,3,-5,6,9,-4,-2,5,14,12,-5,-6,1,8,-15,-10,5,-15,-2,5,3,3,13,-8,-13,8,-5,8,-6,11,-12,3,0,-2,-6,-14,2,0,6,1,-11,9,2,-3,-6,3,3,-15,-5,-14,5,13,-4,-4,-10,-10,11};
	vector<vector<int>> sol=threeSum2(nums);
	cout << endl;
}
