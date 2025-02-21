#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX 10000
#define FINISHED 1

vector<vector<int>> edge, scc;
vector<int> finished, id;
stack<int> s;
int V, E, u, v, idx = 1, cnt = 0;

int notA(int a) {
	return a > MAX ? a - MAX : a + MAX;
}

void init() {
	edge.resize(V * 2 + 1);
	finished.assign(V * 2 + 1, 0);
	id.assign(V * 2 + 1, 0);
}

int SCC(int cur) {
	id[cur] = idx++;
	s.push(cur);

	int ret = id[cur];

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = max(ret, SCC(nxt));
		else if (!finished[nxt]) ret = max(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		vector<int> res;
		while (1) {
			int top = s.top();
			s.pop();
			finished[top] = FINISHED;
			res.push_back(top);
			if (top == cur) break;
		}
		scc.push_back(res);
		cnt++;
	}
}

int solved() {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	init();

	while (E--) {
		cin >> u >> v;
		
		edge[notA(u)].push_back(v);
		edge[notA(v)].push_back(u);
	}

	for (int i = 1; i <= V * 2; i++) if (!id[i]) SCC(i);

	return 0;
}