#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;
const int MAX_SIZE = 101;

vector<pii> cache[MAX_SIZE];
vector<int> res;
queue<int> q;
int dp[MAX_SIZE] = { 0, }, indegree[MAX_SIZE] = { 0, };
int N, M, X, Y, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--) {
		cin >> X >> Y >> K;

		cache[X].push_back({ Y, K });
		indegree[Y]++;
	}

	q.push(N);
	dp[N] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cache[cur].empty()) res.push_back(cur);

		for (auto x : cache[cur]) {
			int nxt = x.first;
			int v = x.second;
			dp[nxt] += dp[cur] * v;
			if (!(--indegree[nxt])) q.push(nxt);
		}
	}
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << " " << dp[x] << "\n";

	return 0;
}