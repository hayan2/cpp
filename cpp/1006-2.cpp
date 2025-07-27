#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 10001;
const int INF = 1e9 + 7;

int N, W;
int cache[2][MAX_N];
int dp[MAX_N][3];

void getResult() {
	for (int i = 2; i <= N; i++) {
		bool vertical = (cache[0][i] + cache[1][i] <= W);
		bool outer = (cache[0][i - 1] + cache[0][i] <= W);
		bool inner = (cache[1][i - 1] + cache[1][i] <= W);

		dp[i][1] = dp[i - 1][0] + 1;
		if (inner) dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);

		dp[i][2] = dp[i - 1][0] + 1;
		if (outer) dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);

		dp[i][0] = min(dp[i][1] + 1, dp[i][2] + 1);
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + (vertical ? 1 : 2));
		if (outer && inner) dp[i][0] = min(dp[i][0], dp[i - 2][0] + 2);
	}
}

void solve() {
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> cache[0][i];
	for (int i = 1; i <= N; i++) cin >> cache[1][i];

	if (N == 1) {
		cout << (cache[0][1] + cache[1][1] <= W ? 1 : 2) << "\n";
		return;
	}

	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = INF;

	int res = INF;

	dp[1][0] = (cache[0][1] + cache[1][1] <= W) ? 1 : 2;
	dp[1][1] = dp[1][2] = 1;
	getResult();
	res = min(res, dp[N][0]);

	if (cache[0][1] + cache[0][N] <= W) {
		dp[1][0] = 2;
		dp[1][1] = 1;
		dp[1][2] = 2;
		getResult();
		res = min(res, dp[N - 1][2] + 1);
	}

	if (cache[1][1] + cache[1][N] <= W) {
		dp[1][0] = 2;
		dp[1][1] = 2;
		dp[1][2] = 1;
		getResult();
		res = min(res, dp[N - 1][1] + 1);
	}

	if (cache[0][1] + cache[0][N] <= W && cache[1][1] + cache[1][N] <= W) {
		dp[1][0] = 2;
		dp[1][1] = 1;
		dp[1][2] = 1;
		getResult();
		res = min(res, dp[N - 2][0] + 2);
	}

	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) solve();


	return 0;
}