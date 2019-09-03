// 20 Dividing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	for (int k = 1;;k++) {
		vector<int> nums(6, 0);
		bool hasNum = false;
		for (int i = 0; i < 6; i++) {
			cin >> nums[i];
			if (nums[i] != 0) {
				hasNum = true;
			}
		}
		if (hasNum == false) {
			break;
		}
		int totalValue = 0;
		for (int i = 0; i < 6; i++) {
			totalValue += nums[i]*(i+1);
		}
		if (totalValue % 2 != 0) {
			cout<<"Collection #"<<k<<':'<<endl;
			cout << "Can't be divided."<<endl;
			cout << endl;
			continue;
		}
		int halfValue = totalValue / 2;
		int sum = 0;
		bool canDiv = false;
		for (int i = 1; i <=6; i++) {
			for (int j = 0; j < nums[i-1]; j++) {
				sum += i;
				if (sum == halfValue) {
					canDiv = true;
				}
				//if (sum > halfValue) {
				//	cout << "Collection #" << k << endl;
				//	cout << "Can't be divided." << endl;
				//	continue;
				//}
			}
		}
		if (canDiv == true) {
			cout << "Collection #" << k << ':' << endl;
			cout << "Can be divided." << endl;
			cout << endl;
		} else {
			cout << "Collection #" << k << ':' << endl;
			cout << "Can't be divided." << endl;
			cout << endl;
		}
	}
}
