// 14 Tram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
#define INF numeric_limits<int>::max()
int Dijkstra(vector<vector<int>>& adj, int src, int dst) {
	int N = adj.size() - 1;
	vector<int> visited(N + 1, 0);
	vector<int> dist(N + 1, INF);
	dist[src] = 0;
	for (int i = 1; i <= N; i++) {
		int idx = -1, minDist = INF;
		for (int j = 1; j <= N; j++) {
			if (visited[j] == 0 && dist[j] < minDist) {
				idx = j;
				minDist = dist[j];
			}
		}
		if (idx == -1) {
			return dist[dst] == INF ? -1 : dist[dst];
		}
		visited[idx] = 1;
		for (int j = 1; j <= N; j++) {
			if (visited[j] == 0 && adj[idx][j] != -1 && dist[idx] + adj[idx][j] < dist[j]) {
				dist[j] = dist[idx] + adj[idx][j];
			}
		}

	}
	return dist[dst] == INF ? -1 : dist[dst];
}
int main() {
	int N, src, dst;
	cin >> N >> src >> dst;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, -1));
	for (int i = 1; i <= N; i++) {
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int k = 0;
			cin >> k;
			if (j == 0) {
				adj[i][k] = 0;
			} else {
				adj[i][k] = 1;
			}
		}
	}
	cout << Dijkstra(adj, src, dst) << endl;
}

