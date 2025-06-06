#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
using pii = pair<int, int>;
const int INF = 1e9 + 7;
const int MAX_SIZE = 1003;

vector<pii> cache;
int dp[MAX_SIZE], C, N, res = INF;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, INF, sizeof dp);

	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		int u, w;
		cin >> u >> w;
		cache.push_back({ u, w });
	}
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < C; j++) {
			dp[j + cache[i].second] = min(dp[j + cache[i].second], dp[j] + cache[i].first);
			if (j + cache[i].second >= C) res = min(res, dp[j + cache[i].second]);
		}
	}

	cout << res;

	return 0;
}