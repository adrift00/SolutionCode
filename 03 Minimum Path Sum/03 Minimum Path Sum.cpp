// 03 Minimum Path Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int PathSum(vector<vector<int>>& grid) 
//{
//	int m = grid.size();
//	int n = grid[0].size();
//	vector<vector<int>> pathLength(m, vector<int>(n,1000000));
//	queue<int> curRow;
//	queue<int> curCol;
//	curRow.push(m - 1);
//	curCol.push(n - 1);
//	pathLength[m - 1][n - 1] = grid[m - 1][n - 1];
//	vector<vector<int>> isVisit(m, vector<int>(n, 0));
//	while (!curCol.empty())
//	{
//		int x = curRow.front();
//		int y = curCol.front();
//		//cout << x << ' ';
//		//cout << y << endl;
//		int downLength = 100000, rightLength = 100000;
//		int hasBefore = 0;
//		if (x - 1 >= 0&&isVisit[x-1][y]==0)
//		{
//			downLength = grid[x - 1][y] + pathLength[x][y];
//			if (y + 1 < n)
//			{
//				rightLength = grid[x - 1][y] + pathLength[x - 1][y + 1];
//			}
//			if (downLength < rightLength)
//			{
//				pathLength[x - 1][y] = downLength;
//			}
//			else
//			{
//				pathLength[x-1][y] = rightLength;
//			}
//			curRow.push(x - 1);
//			curCol.push(y);
//			isVisit[x - 1][y] = 1;
//		}
//		downLength = 100000;
//		rightLength = 100000;
//		if (y - 1 >= 0 && isVisit[x ][y-1] == 0)
//		{
//			rightLength = grid[x][y - 1] + pathLength[x][y];
//			if (x + 1 < m)
//			{
//				downLength = grid[x][y - 1] + pathLength[x + 1][y - 1];
//			}
//			if (downLength < rightLength)
//			{
//				pathLength[x][y-1] = downLength;
//			}
//			else
//			{
//				pathLength[x][y-1] = rightLength;
//			}
//			curRow.push(x);
//			curCol.push(y-1);
//			isVisit[x][y - 1] = 1;
//		}
//		curRow.pop();
//		curCol.pop();
//	}
//	return pathLength[0][0];
//}
int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> pathLength(m, vector<int>(n, 0));
	for (int i = m - 1; i >= 0; i--){
		for (int j = n - 1; j >= 0; j--){
			if (i == m - 1 && j == n - 1) {
				pathLength[i][j] = grid[i][j];
			}else if (i == m - 1) {
				pathLength[i][j] = grid[i][j] + pathLength[i][j + 1];
			}else if (j == n - 1) {
				pathLength[i][j] = grid[i][j] + pathLength[i+1][j];
			}
			else {
				pathLength[i][j] = min(grid[i][j] + pathLength[i][j + 1], grid[i][j] + pathLength[i+1][j]);
			}
		}
	}
	return pathLength[0][0];
}
int main()
{
	vector<vector<int>> grid{{ 1,4,8,6,2,2,1,7 }, { 4,7,3,1,4,5,5,1 }, { 8,8,2,1,1,8,0,1 }, { 8,9,2,9,8,0,8,9 }, \
																{ 5,7,5,7,1,8,5,5 }, { 7,0,9,4,5,6,5,6 }, { 4,9,9,7,9,1,9,0 }};
	int minPathLength = minPathSum(grid);
	cout << minPathLength << endl;
}