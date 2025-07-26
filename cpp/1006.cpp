#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_N = 10001;
const int INF = 1e9 + 7;

int dp[MAX_N][3];
int zone[2][MAX_N];
int T, N, W;

void solve() {	
	cin >> N >> W;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> zone[i][j];
		}
	}
	
	memset(&dp, 0, sizeof(dp));

	dp[0][0] = 0;
	dp[0][1] = INF;
	dp[0][2] = INF;

	for (int i = 1; i <= N; i++) {
		int alone = dp[i - 1][0] + (zone[0][i] + zone[1][i] <= W ? 1 : 2);
		int outer = dp[i - 1][0] + 1;
		int inner = dp[i - 1][0] + 1;

		int outerPair = (zone[0][i - 1] + zone[0][i] <= W) ? dp[i - 1][2] + 1 : INF;
		int innerPair = (zone[1][i - 1] + zone[1][i] <= W) ? dp[i - 1][1] + 1 : INF;

		dp[i][0] = min({ alone, outerPair, innerPair });
		dp[i][1] = outer;
		dp[i][2] = inner;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	while (T--) solve();

	return 0;
}