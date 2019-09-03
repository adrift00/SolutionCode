// 17 Packing Boxes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int PackingBoxes(vector<int> boxNums) {
	int boxCount = 0;
	vector<int> freeSpace(4,0);
	boxCount = boxNums[4] + boxNums[5] + boxNums[6];
	boxCount += boxNums[3] / 4 + 1;
	if (boxNums[3] % 4 == 1) {
		freeSpace[2] += 5;
		freeSpace[1] += 7;
	} else if (boxNums[3] % 4 == 2) {
		freeSpace[2] +=3;
		freeSpace[1] += 6;
	} else if (boxNums[3] % 4 == 3) {
		freeSpace[2] += 1;
		freeSpace[1] += 5;
	}
	freeSpace[2] += 5 * boxNums[4];
	freeSpace[1] += 11 * boxNums[5];
	if (boxNums[2] <= freeSpace[2]) {
		freeSpace[1] += 4 * (freeSpace[2] - boxNums[2]);
	} else {
		boxCount += (boxNums[2] - freeSpace[2]) / 9 + 1;
		freeSpace[1] += (9 - (boxNums[2] - freeSpace[2]) % 9) * 4;
	}
	if (boxNums[1] > freeSpace[1]) {
		boxCount += (boxNums[1] - freeSpace[1]) / 36 + 1;
	}
	return boxCount;
}

int main()
{
	vector<int> boxNums = { 0,7, 5, 1, 0, 0, 0 };
	cout << PackingBoxes(boxNums) << endl;
}