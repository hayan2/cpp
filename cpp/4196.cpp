#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// WA

#define MAX_N 100001
#define FINISHED true

vector<int> edge[MAX_N];
stack<int> s;
int id[MAX_N] = { 0, };
bool finished[MAX_N] = { 0, };
int T, N, M, u, v, res = 0, idx = 1;

void init() {
	res = 0, idx = 1;
	memset(id, 0, sizeof(id));
	memset(finished, 0, sizeof(finished));
	for (int i = 1; i <= N; i++) edge[i].clear();
}

int solved(int cur) {
	id[cur] = idx++;
	s.push(cur);

	int ret = id[cur];

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = min(ret, solved(nxt));
		else if (!finished) ret = min(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		while (1) {
			int top = s.top();
			s.pop();
			finished[top] = FINISHED;
			if (top == cur) break;
		}
		res++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> M;
		res = N;
		for (int i = 0; i < M; i++) {
			cin >> u >> v;

			edge[u].push_back(v);
		}

		for (int i = 1; i <= N; i++) if (!id[i]) solved(i);

		cout << res << "\n";
		init();
	}

	return 0;
}