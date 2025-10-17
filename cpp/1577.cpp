#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX_DP = 101;

set<pair<pii, pii>> blockedPath;
ll dp[MAX_DP][MAX_DP] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		pii p1 = { min(a, c), min(b, d) };
		pii p2 = { max(a, c), max(b, d) };
		blockedPath.insert({ p1, p2 });
	}

	dp[0][0] = 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i > 0) {
				pii p1 = { i - 1, j };
				pii p2 = { i, j };

				if (blockedPath.find({ p1, p2 }) == blockedPath.end()) {
					dp[i][j] += dp[i - 1][j];
				}
			}

			if (j > 0) {
				pii p1 = { i, j - 1 };
				pii p2 = { i, j };

				if (blockedPath.find({ p1, p2 }) == blockedPath.end()) {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
	}

	cout << dp[N][M];

	return 0;
}