#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n, m, x, y;
vector<pair<int, int>> bus[880];
int dijkstra(int s, int e) {
	priority_queue<pair<int, int>> pq;
	vector<int> vst(880, INF);
	pq.push({ 0,s });
	while (!pq.empty()) {
		int l = -pq.top().first;
		int nd = pq.top().second;
		pq.pop();
		if (vst[nd] < l) continue;
		vst[nd] = l;
		for (int i = 0; i < bus[nd].size(); i++) {
			int ll = l + bus[nd][i].second;
			int ndnd = bus[nd][i].first;
			if (vst[ndnd] > ll) {
				vst[ndnd] = ll;
				pq.push({ -ll,ndnd });
			}
		}
	}
	return vst[e];
}
int main() {
	//if -> 만약 ~라면 -> 실행
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bus[a].push_back({ b,c });
		bus[b].push_back({ a,c });
	}
	scanf("%d %d", &x, &y);
	int la = dijkstra(1, x) + dijkstra(x, y) + dijkstra(y, n);
	int lb = dijkstra(1, y) + dijkstra(x, y) + dijkstra(x, n);
	if (la == INF && lb == INF) printf("-1");
	else printf("%d", min(la, lb));
	return 0;
}