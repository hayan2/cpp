#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const int MAX_N = 1001;

vector<pii> adj[MAX_N];
int N, M;

int solve(int s, int e) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		int u = cur.second;
		int cost = cur.first;

		if (dist[u] < cost) continue;

		for (auto& edge : adj[u]) {
			int nxtNode = edge.first;
			int edgeCost = edge.second;
			int newCost = edgeCost + cost;

			if (newCost < dist[nxtNode]) {
				dist[nxtNode] = newCost;
				pq.push({ newCost, nxtNode });
			}
		}
	}

	return dist[e];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> M;	
	
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
	}

	int s, e;
	cin >> s >> e;

	cout << solve(s, e);

	return 0;
}