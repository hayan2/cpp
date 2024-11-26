#define MAX_LEN 100001
#define ROOT 1
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

vector<pair<int, int>> tree[MAX_LEN];
int cache[MAX_LEN] = { 0, };
int visited[MAX_LEN] = { 0, };
int V;

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
			if (!visited[tree[u][i].first]) {
				visited[tree[u][i].first] = VISITED;
				queue.push({ tree[u][i].first, tree[u][i].second + w });
				cache[tree[u][i].first] = w + tree[u][i].second; // > cache[tree[u][i].first] ? cache[u] + w : cache[tree[u][i].first];
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (distance < cache[i]) {
			ret = i;
			distance = cache[i];
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
			if (!visited[tree[u][i].first]) {
				visited[tree[u][i].first] = VISITED;
				queue.push({ tree[u][i].first, tree[u][i].second + w });
				cache[tree[u][i].first] = w + tree[u][i].second; // > cache[tree[u][i].first] ? cache[u] + w : cache[tree[u][i].first];
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		ret = cache[i] > ret ? cache[i] : ret;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;

	cin >> V;

	for (int i = 0; i < V; i++) {
		cin >> u;
		while (1) {
			cin >> v;
			if (v == -1) {
				break;
			}
			cin >> w;

			tree[u].push_back({ v, w });
		}
	}
		
	cout << solved(getFurthestNode(ROOT));

	return 0;
}