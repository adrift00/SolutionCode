// 25 Wormholes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()/2
typedef struct Node {
	int v;
	int w;
}Node;
bool BellmanFold(vector<vector<Node>>& adj, int src) {
	int N = adj.size() - 1;
	vector<int> dist(N + 1, INF);
	dist[src] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int u = 1; u <= N; u++) {
			for (int k = 0; k < adj[u].size(); k++) {
				int v = adj[u][k].v;
				int w = adj[u][k].w;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
				}
			}
		}
	}
	for (int u = 1; u <= N; u++) {
		for (int k = 0; k < adj[u].size(); k++) {
			int v = adj[u][k].v;
			int w = adj[u][k].w;
			if (dist[u] + w < dist[v]) {
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int num_farms;
	cin >> num_farms;
	while (num_farms--) {
		int N, M, W;
		cin >> N >> M >> W;
		vector<vector<Node>> adj(N + 1, vector<Node>());
		for (int i = 0; i < M; i++) {
			Node node1, node2;
			cin >> node1.v >> node2.v >> node1.w;
			node2.w = node1.w;
			adj[node1.v].push_back(node2);
			adj[node2.v].push_back(node1);

		}
		for (int i = 0; i < W; i++) {
			Node node1, node2;
			cin >> node1.v >> node2.v >> node2.w;
			node2.w = -node2.w;
			adj[node1.v].push_back(node2);
		}
		if (BellmanFold(adj, 1) == true) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
}