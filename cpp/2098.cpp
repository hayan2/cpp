#define MAX_LEN 16
#define INF 1e9
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int cache[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][1 << MAX_LEN];
int N;

int solved(int cur, int state) {
	if (state == (1 << N) - 1) {
		if (!cache[cur][0]) return INF;
		return cache[cur][0];
	}
	if (dp[cur][state] != -1) return dp[cur][state];

	dp[cur][state] = INF;
	for (int i = 0; i < N; i++) {
		if (!cache[cur][i]) continue;
		if (!(state & (1 << i))) {
			dp[cur][state] = min(dp[cur][state], solved(i, state | (1 << i)) + cache[cur][i]);
		}
	}

	return dp[cur][state];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cache[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solved(0, 1);

	return 0;
}