#define MAX_LEN 10001
#define ROOT 1
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<pair<int, int>> tree[MAX_LEN];
int cache[MAX_LEN] = { 0, };
int visited[MAX_LEN] = { 0, };
int N;

int getFurthestNode(int s) {
	queue<pair<int, int>> queue;
	int distance = 0, ret = 0;
	
	queue.push({ s, 0 });
	visited[s] = VISITED;

	while (!queue.empty()) {
		int u = queue.front().first;
		int w = queue.front().second;
		queue.pop();

		for (int i = 0; i < tree[u].size(); i++) {
			int v = tree[u][i].first;
			if (!visited[v]) {
				queue.push({ v, tree[u][i].second + w });
				visited[v] = VISITED;
				cache[v] = tree[u][i].second + w;
				if (cache[v] > distance) {
					distance = cache[v];
					ret = v;
				}
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	memset(cache, 0, sizeof(cache));

	return ret;
}

int solved(int s) {
	queue<pair<int, int>> queue;
	int ret = 0;

	queue.push({ s, 0 });
	visited[s] = VISITED;

	while (!queue.empty()) {
		int u = queue.front().first;
		int w = queue.front().second;
		queue.pop();

		for (int i = 0; i < tree[u].size(); i++) {
			int v = tree[u][i].first;
			if (!visited[v]) {
				queue.push({ v, tree[u][i].second + w });
				visited[v] = VISITED;
				cache[v] = tree[u][i].second + w;
				ret = cache[v] > ret ? cache[v] : ret;
			}
		}
	}

	return ret;	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int u, v, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		
		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}

	cout << solved(getFurthestNode(ROOT));

	return 0;
}