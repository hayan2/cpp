#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10005;
const int INF = 1e9 + 7;

int cache[2][MAX_N];
int dp[MAX_N][3];
int N, W;

void solve() {
	for (int i = 2; i <= N; i++) {
		int outer = (cache[0][i - 1] + cache[0][i] <= W ? 1 : 2);
		int inner = (cache[1][i - 1] + cache[1][i] <= W ? 1 : 2);
		int vertical = (cache[0][i] + cache[1][i] <= W ? 1 : 2);

		dp[i][0] = min({ dp[i - 1][0] + vertical, dp[i - 2][0] + outer + inner, dp[i - 1][1] + outer + 1, dp[i - 1][2] + 1 + inner });
		dp[i][1] = min(dp[i - 1][2] + inner, dp[i - 1][0] + 1);
		dp[i][2] = min(dp[i - 1][1] + outer, dp[i - 1][0] + 1);
	}
}

void getResult() {
	cin >> N >> W;

	for (int i = 1; i <= N; i++) cin >> cache[0][i];
	for (int i = 1; i <= N; i++) cin >> cache[1][i];

	if (N == 1) {
		cout << (cache[0][1] + cache[1][1] <= W ? 1 : 2) << "\n";
		return;
	}

	int outer = cache[0][1];
	int inner = cache[1][1];

	int res = INF;

	dp[1][0] = (cache[0][1] + cache[1][1] <= W ? 1 : 2);
	dp[1][1] = dp[1][2] = 1;
	solve();
	res = min(res, dp[N][0]);

	if (cache[0][1] + cache[0][N] <= W) {
		dp[1][0] = 2;
		dp[1][1] = 1;
		dp[1][2] = 1;
		cache[0][1] = INF;
		solve();
		res = min(res, dp[N][1]);
		cache[0][1] = outer;
	}

	if (cache[1][1] + cache[1][N] <= W) {
		dp[1][0] = 2;
		dp[1][1] = 1;
		dp[1][2] = 1;
		cache[1][1] = INF;
		solve();
		res = min(res, dp[N][2]);
		cache[1][1] = inner;
	}

	if (cache[0][1] + cache[0][N] <= W && cache[1][1] + cache[1][N] <= W) {
		cache[0][1] = INF;
		cache[1][1] = INF;
		dp[1][0] = 2;
		dp[1][1] = 1;
		dp[1][2] = 1;
		solve();
		res = min(res, dp[N - 1][0]);
		cache[0][1] = outer;
		cache[1][1] = inner;
	}

	cout << res << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) getResult();

	return 0;
}