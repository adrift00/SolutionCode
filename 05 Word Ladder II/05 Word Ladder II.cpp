// 05 Word Ladder II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef struct {
	int pathLength;
	int lastIndex;
}ShortPath;
vector<vector<int>> CreateAdj(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<int>> adj(wordList.size() + 1, vector<int>(wordList.size() + 1));
	for (int i = 0; i < wordList.size(); i++) {
		int sum = 0;
		for (int j = 0; j < beginWord.length(); j++) {
			if (beginWord[j] != wordList[i][j]) {
				sum += 1;
			}
		}
		if (sum == 1) {
			adj[0][i + 1] = 1;
		}
	}
	for (int i = 0; i < wordList.size(); i++) {
		for (int j = 0; j < wordList.size(); j++) {
			int sum = 0;
			for (int k = 0; k < wordList[i].length(); k++) {
				if (wordList[i][k] != wordList[j][k]) {
					sum += 1;
				}
			}
			if (sum == 1) {
				adj[i + 1][j + 1] = 1;
			}
		}
	}
	return adj;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<int>> adj = CreateAdj(beginWord, endWord, wordList);
	vector<vector<string>> ladders;
	int beginIndex = 0;
	auto it = find(wordList.begin(), wordList.end(), endWord);
	if (it == wordList.end()) {
		return ladders;
	}
	int endIndex = it - wordList.begin()+1;
	int m = wordList.size() + 1;
	vector<ShortPath> shortPath(m);
	vector<int> visited;
	vector<int> unvisited;
	for (int i = 0; i < m; i++) {
		unvisited.push_back(i);
	}
	auto idx = find(unvisited.begin(), unvisited.end(), beginIndex);
	unvisited.erase(idx);
	shortPath[0].pathLength = 0;
	shortPath[0].lastIndex = beginIndex;
	visited.push_back(beginIndex);
	while (!unvisited.empty()) {
		int newEnd = 0,newBegin=0, minLength = INT_MAX;
		for (int i = 0; i < visited.size(); i++) {
			for (int j = 0; j < unvisited.size(); j++) {
				if (adj[visited[i]][unvisited[j]] == 1) {
					if (shortPath[visited[i]].pathLength + 1 < minLength) {
						newBegin = visited[i];
						newEnd = unvisited[j];
						minLength = shortPath[visited[i]].pathLength + 1;
					}
				}
			}
		}
		if (minLength == INT_MAX) {
			return ladders;
		}
		shortPath[newEnd].pathLength = minLength;
		shortPath[newEnd].lastIndex = newBegin;
		auto idx = find(unvisited.begin(), unvisited.end(), newEnd);
		unvisited.erase(idx);
		visited.push_back(newEnd);
	}
	int i = endIndex;
	ladders.push_back(vector<string>());
	while (i!=beginIndex) {
		ladders[0].push_back(wordList[i - 1]);
		i = shortPath[i].lastIndex;
	}
	return ladders;
}



int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList{ "hot", "dot", "dog", "lot", "log", "cog" };
	vector<vector<int>> adj = CreateAdj(beginWord, endWord, wordList);
	vector<vector<string>> ladders;
	ladders=findLadders(beginWord, endWord, wordList);
	for (int i = 0; i < ladders[0].size(); i++) {
		cout << ladders[0][i] << ' ';
	}
}