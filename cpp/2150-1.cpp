#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX_V 10001 
#define FINISHED 1

vector<int> edge[MAX_V];
vector<vector<int>> res;
stack<int> s;
bool finished[MAX_V] = { 0, };
int id[MAX_V] = { 0, };
int V, E, u, v, idx = 1, cnt = 0;

int solved(int cur) {
	id[cur] = idx++;
	s.push(cur);

	int ret = id[cur];

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = min(ret, solved(nxt));
		else if (!finished[nxt]) ret = min(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		vector<int> scc;

		while (1) {
			int top = s.top();
			s.pop();
			scc.push_back(top);
			finished[top] = FINISHED;			
			if (top == cur) break;
		}

		sort(scc.begin(), scc.end());
		res.push_back(scc);
		cnt++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	
	for (int i = 0; i < E; i++) {
		cin >> u >> v;

		edge[u].push_back(v);
	}

	for (int i = 1; i <= V; i++) if(!id[i]) solved(i);
	sort(res.begin(), res.end());

	cout << cnt << "\n";
	for (auto cur : res) {
		for (auto x : cur) {
			cout << x << " ";
		}
		cout << "-1\n";
	}

	return 0;
}