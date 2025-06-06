#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
using pii = pair<int, int>;
const int INF = 1e9 + 7;
const int MAX_COST = 100001;

vector<pii> cache;
int dp[MAX_COST], C, N, res = INF;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, INF, sizeof dp);

	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		int u, w;
		cin >> u >> w;

		dp[w] = min(dp[w], u);
		cache.push_back({ u, w });
	}

	for (int i = 1; i <= MAX_COST; i++) {
		for (int j = 0; j < N; j++) {
			if (i - cache[j].second > -1) {
				dp[i] = min(dp[i], dp[i - cache[j].second] + cache[j].first);
			}			
			if (i >= C) res = min(res, dp[i]);
		}
		if (i > C && dp[i] > res) {
			cout << res;
			return 0;
		}
	}


	return 0;
}