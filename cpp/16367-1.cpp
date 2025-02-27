#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_N 10000
#define MAX_K 5000
#define VISITED 1

typedef pair<int, int> type;

vector<int> edge[MAX_N * 2 + 1], redge[MAX_N * 2 + 1];
vector<vector<int>> scc;
vector<int> st;
int visited[MAX_N * 2 + 1], id[MAX_N * 2 + 1];
int N, M, idx = 1, cnt = 1;

int notA(int a) { return a > N ? a - N : a + N; }
int isNegative(int a) { return a < 0 ? -a : a + N; }

void dfs(int cur) {
	visited[cur] = VISITED;
	for (auto nxt : edge[cur]) if (!visited[nxt]) dfs(nxt);
	st.push_back(cur);
}

void rdfs(int cur) {
	visited[cur] = VISITED;
	id[cur] = idx;
	for (auto nxt : redge[cur]) if (!visited[nxt]) rdfs(nxt);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--) {
		char c1, c2, c3;
		int l1, l2, l3;

		cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;

		l1 = isNegative(l1);
		l2 = isNegative(l2);
		l3 = isNegative(l3);

		if (c1 == 'B') l1 = notA(l1);
		if (c2 == 'B') l2 = notA(l2);
		if (c3 == 'B') l3 = notA(l3);

		// (l1 or l2) and (l2 or l3) and (l3 or l1)
		edge[notA(l1)].push_back(l2);
		edge[notA(l2)].push_back(l1);
		edge[notA(l2)].push_back(l3);
		edge[notA(l3)].push_back(l2);
		edge[notA(l3)].push_back(l1);
		edge[notA(l1)].push_back(l3);
		redge[l1].push_back(notA(l2));
		redge[l2].push_back(notA(l1));
		redge[l2].push_back(notA(l3));
		redge[l3].push_back(notA(l2));
		redge[l3].push_back(notA(l1));
		redge[l1].push_back(notA(l3));
	}

	for (int i = 1; i <= N * 2; i++) if (!visited[i]) dfs(i);
	reverse(st.begin(), st.end());
	memset(visited, 0, sizeof(visited));
	for (auto x : st) {
		if (!visited[x]) {
			rdfs(x);
			idx++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (id[i] == id[i + N]) {
			cout << "-1";
			return 0;
		}
	}

	vector<type> tmp;

	for (int i = 1; i <= N * 2; i++) tmp.push_back({ id[i], i });
	sort(tmp.begin(), tmp.end(), greater<type>());

	vector<int> res(N * 2 + 1, -1);
	for (int i = 0; i < tmp.size(); i++) {
		int cur = tmp[i].second;
		if (res[cur] == -1) {
			res[cur] = 0;
			res[notA(cur)] = 1;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (!res[i]) cout << "B";
		else cout << "R";
	}

	return 0;
}