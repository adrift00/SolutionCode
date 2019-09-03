// 08 Surrounded Regions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
void Dfs(vector<vector<char>>& board, int i, int j) {
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') {
		return;
	}
	board[i][j] = '#';
	Dfs(board, i - 1, j);
	Dfs(board, i + 1, j);
	Dfs(board, i, j - 1);
	Dfs(board, i, j + 1);
}
void Solve(vector<vector<char>>& board) {
	if (board.size() == 0) {
		return;
	}
	for (int i = 0; i < board.size(); i++) {
		Dfs(board, i, 0);
		Dfs(board, i, board[0].size() - 1);
	}
	for (int j = 0; j < board[0].size(); j++) {
		Dfs(board, 0, j);
		Dfs(board, board.size() - 1, j);
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
			if (board[i][j] == '#') {
				board[i][j] = 'O';
			}
		}
	}
}
int main() {
	vector<vector<char>> board = { {'X','X','X','X'},
								  {'X','O','O','X'},
								  {'X','X','O','X'},
								  {'X','O','X','X'} };
	Solve(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}