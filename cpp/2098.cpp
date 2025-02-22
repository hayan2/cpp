#define MAX_LEN 16
#define INF 1e9
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int sccidx[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][1 << MAX_LEN];
int V;

int solved(int cur, int state) {
	if (state == (1 << V) - 1) {
		if (!sccidx[cur][0]) return INF;
		return sccidx[cur][0];
	}
	if (dp[cur][state] != -1) return dp[cur][state];

	dp[cur][state] = INF;
	for (int i = 0; i < V; i++) {
		if (!sccidx[cur][i]) continue;
		if (!(state & (1 << i))) {
			dp[cur][state] = min(dp[cur][state], solved(i, state | (1 << i)) + sccidx[cur][i]);
		}
	}

	return dp[cur][state];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cin >> sccidx[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solved(0, 1);

	return 0;
}