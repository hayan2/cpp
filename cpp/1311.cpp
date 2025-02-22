#define MAX_LEN 25
#define INF 1e10
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int sccidx[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][1 << 20];
int V;

int solved(int cur, int state) {
	if (state == (1 << V) - 1) return 0;
	if (dp[cur][state] != -1) return dp[cur][state];

	dp[cur][state] = INF;
	for (int i = 0; i < V; i++) {
		if (!(state & (1 << i))) {
			dp[cur][state] = min(dp[cur][state], solved(cur + 1, state | (1 << i)) + sccidx[cur][i]);
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
	cout << solved(0, 0);

	return 0;
}