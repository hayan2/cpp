#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAX_N 10000
#define MAX_K 5000

vector<int> edge[MAX_N * 2 + 1], redge[MAX_N * 2 + 1];
vector<vector<int>> scc;
stack<int> s;
int id[MAX_N * 2 + 1] = { 0, }, finished[MAX_N * 2 + 1], cache[MAX_N * 2 + 1];
int N, M, idx = 1, cnt = 1;

int notA(int a) { return a > N ? a - N : a + N; }
int isNegative(int a) { return a < 0 ? -a : a + N; }

int SCC(int cur) {
	int ret = id[cur] = idx++;
	s.push(cur);

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = min(ret, SCC(nxt));
		else if (!finished[nxt]) ret = min(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		vector<int> res;

		while (1) {
			int top = s.top();
			s.pop();
			cache[top] = cnt;
			res.push_back(top);
			if (top == cur) break;
		}
		scc.push_back(res);
		cnt++;
	}

	return ret;
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
	}



	return 0;
}