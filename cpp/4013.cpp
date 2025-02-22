#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_LEN 500001
#define FINISHED 1
#define LOOP 1

vector<vector<int>> sccEdge, edge, scc;
vector<int> finished, indegree, sccidx, sccidx, cost, id, dp, restaurant;
stack<int> s;
queue<int> q;
int V, E, S, P, u, v, w, n, idx = 1, cnt = 1;

void init() {	
	edge.resize(V + 1);
	sccidx.assign(V + 1, 0);
	finished.assign(V + 1, 0);
	sccidx.assign(V + 1, 0);
	cost.assign(V + 1, 0);
	id.assign(V + 1, 0);
	dp.assign(V + 1, 0);
}

int SCC(int cur) {
	id[cur] = idx++;
	s.push(cur);

	int ret = id[cur];

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = min(ret, SCC(nxt));
		else if (!finished[nxt]) ret = min(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		vector<int> res;

		while (LOOP) {
			int top = s.top();
			s.pop();
			finished[top] = FINISHED;
			sccidx[top] = cnt;
			sccidx[cnt] += cost[top];
			res.push_back(top);
			if (top == cur) break;
		}
		sort(res.begin(), res.end());
		scc.push_back(res);
		cnt++;
	}

	return ret;	
}

void getIndegree() {
	sccEdge.resize(cnt + 1);	
	indegree.assign(cnt + 1, 0);

	for (int i = 1; i <= V; i++) {
		for (auto x : edge[i]) {
			if (sccidx[i] != sccidx[x]) {
				sccEdge[sccidx[i]].push_back(sccidx[x]);
				++indegree[sccidx[x]];
			}
		}
	}
}

void solved() {
	for (int i = 1; i < cnt; i++) if (!indegree[i]) q.push(i);

	bool flag = false;

	dp[sccidx[S]] = sccidx[sccidx[S]];

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == sccidx[S]) flag = true;

		for (auto nxt : sccEdge[cur]) {
			if (flag) dp[nxt] = max(dp[nxt], dp[cur] + sccidx[nxt]);			
			if (!(--indegree[nxt])) q.push(nxt);
		}
	}	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	init();
	
	for (int i = 0; i < E; i++) {
		cin >> u >> v;

		edge[u].push_back(v);
	}

	for (int i = 1; i <= V; i++) {
		cin >> cost[i];
	}

	for (int i = 1; i <= V; i++) if (!id[i]) SCC(i);

	cin >> S >> P;

	for (int i = 0; i < P; i++) {
		cin >> n;

		restaurant.push_back(n);
	}

	getIndegree();
	solved();
	
	int res = 0;

	for (int i = 0; i < P; i++) res = max(res, dp[sccidx[restaurant[i]]]);

	cout << res;

	return 0;
}