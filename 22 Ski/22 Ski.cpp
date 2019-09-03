// 22 Ski.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(vector<vector<int>>& land, int x, int y, vector<vector<int>>& maxLenth) {
	int numRows = land.size(), numCols = land[0].size();
	int up = 1, down = 1, left = 1, right = 1;
	if (x - 1 >= 0 && land[x - 1][y] < land[x][y]) {
		int maxlen = maxLenth[x - 1][y] == -1 ? DFS(land, x - 1, y, maxLenth) : maxLenth[x - 1][y];
		up = maxlen + 1;
	}
	if (x + 1 < numRows && land[x + 1][y] < land[x][y]) {
		int maxlen = maxLenth[x + 1][y] == -1 ? DFS(land, x + 1, y, maxLenth) : maxLenth[x + 1][y];
		down = maxlen + 1;
	}
	if (y - 1 >= 0 && land[x][y - 1] < land[x][y]) {
		int maxlen = maxLenth[x][y-1] == -1 ? DFS(land, x, y - 1, maxLenth) : maxLenth[x][y - 1];
		left = maxlen + 1;
	}
	if (y + 1 < numCols && land[x][y + 1] < land[x][y]) {
		int maxlen = maxLenth[x][y + 1] == -1 ? DFS(land, x, y + 1, maxLenth) : maxLenth[x][y + 1];
		right = maxlen + 1;
	}
	maxLenth[x][y] = max(max(up, down), max(left, right));
	return maxLenth[x][y];
}
int main()
{
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int>> land(rows, vector<int>(cols));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> land[i][j];
		}
	}
	vector<vector<int>> maxLength(rows, vector<int>(cols,-1));
	int maxlen = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			maxLength[i][j] = DFS(land, i, j,maxLength);
			if (maxLength[i][j] > maxlen) {
				maxlen = maxLength[i][j];
			}
		}
	}
	cout << maxlen << endl;

}