// 30 Edge Detection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int width = 0;
int height = 0;

typedef struct Pixel {
	int idx;
	int val;
}Pixel;

bool Cmp(Pixel a, Pixel b) {
	return a.idx < b.idx;
}

int GetVal(vector<Pixel>& originBeginPixels, int idx) {
	int i = 0;
	while (originBeginPixels[i].idx <= idx) {
		i++;
	}
	return originBeginPixels[i - 1].val;
}

Pixel CalcOutput(vector<Pixel>& originBeginPixels, int idx) {
	int val = GetVal(originBeginPixels,idx);
	int row = ceil(idx * 1.0 / width * 1.0);
	int col = idx - (width * (row - 1));
	int maxSubVal = 0;
	for (int curRow = row -1; curRow < row+2; curRow++) {
		for (int curCol = col -1; curCol < col+2; curCol++) {
			if (curRow<1 || curRow>height || curCol<1 || curCol>width) {
				continue;
			}
			int curIdx = (curRow - 1) * width + curCol;
			int curVal = GetVal(originBeginPixels, curIdx);
			maxSubVal = max(abs(curVal - val), maxSubVal);
		}
	}
	Pixel newPix = { idx, maxSubVal };
	return newPix;
}


int main()
{
	while (cin >> width && width != 0) {
		vector<Pixel> originBeginPixels;
		vector<Pixel> newBeginPixels;
		int beginIdx = 1;
		int totalPixNum = 0;
		int val, length;
		while (cin >> val >> length && !(val == 0 && length == 0)) {
			Pixel pix = { beginIdx,val };
			originBeginPixels.push_back(pix);
			beginIdx += length;
		}
		Pixel pix = { beginIdx,0 };
		originBeginPixels.push_back(pix);//多加入了一个，否则最后一行会出错
		totalPixNum = beginIdx - 1;
		height = totalPixNum / width;
		for (int i = 0; i < originBeginPixels.size(); i++) {
			int beginIdx = originBeginPixels[i].idx;
			int beginRow = ceil(beginIdx * 1.0 / width * 1.0);
			int beginCol = beginIdx - (width * (beginRow - 1));
			//将周围8个点和自己加入到候选区里
			for (int curRow = beginRow-1; curRow < beginRow+2; curRow++) {
				for (int curCol = beginCol -1; curCol < beginCol+2; curCol++) {
					if (curRow<1 || curRow>height || curCol<1 || curCol>width) {
						continue;
					}
					int curIdx = (curRow - 1) * width + curCol;
					Pixel newPix = CalcOutput(originBeginPixels,curIdx);
					newBeginPixels.push_back(newPix);
				}
			}
		}
		sort(newBeginPixels.begin(), newBeginPixels.end(), Cmp);
		//输出结果
		cout << width << endl;
		Pixel curpix = newBeginPixels[0];
		for (int i = 0; i < newBeginPixels.size(); i++) {
			if (newBeginPixels[i].val == curpix.val) {
				continue;
			}
			cout << curpix.val << " " << newBeginPixels[i].idx - curpix.idx << endl;
			curpix = newBeginPixels[i];
		}
		cout << curpix.val << " " << (totalPixNum + 1) - curpix.idx << endl;
		cout << 0 << " " << 0 << endl;
	}
	cout << 0 << endl;
}