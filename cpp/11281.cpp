#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX 10000
#define FINISHED 1

vector<vector<int>> edge, scc;
vector<int> finished, id, sccidx;
stack<int> s;
int cache[MAX * 2 + 1] = { 0, };
int V, E, u, v, idx = 1, cnt = 1;

int notA(int a) { return a > MAX ? a - MAX : a + MAX; }
int isNegative(int a) { return a < 0 ? -a : a + MAX; }

void init() {
	edge.resize(MAX * 2 + 1);
	finished.assign(MAX * 2 + 1, 0);
	id.assign(MAX * 2 + 1, 0);
	sccidx.assign(MAX * 2 + 1, 0);
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

		while (1) {
			int top = s.top();
			s.pop();
			finished[top] = FINISHED;
			sccidx[top] = cnt;
			res.push_back(top);
			if (top == cur) break;
		}
		scc.push_back(res);
		cnt++;
	}

	return ret;
}

int solved() {
	for (int i = 1; i <= V; i++) {
		if (sccidx[i] == sccidx[i + MAX]) return 0;
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	init();

	while (E--) {
		cin >> u >> v;

		u = isNegative(u);
		v = isNegative(v);
		edge[notA(u)].push_back(v);
		edge[notA(v)].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if (!id[i]) SCC(i);
		if (!id[notA(i)]) SCC(i);
	}

	if (!solved()) cout << "0";
	else {		
		cout << "1\n";
		for (auto x : scc) {
			for (auto cur : x) {
				if (!cache[cur]) {
					cache[cur] = 0;
					cache[notA(cur)] = 1;
				}
			}
		}

		for (int i = 1; i <= V; i++) cout << cache[i] << " ";
	}

	return 0;
}