#define INF 1e9
#define MAX_LEN 1002
#define COLOR_LEN 3	
#define RED 0
#define GREEN 1
#define BLUE 2
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int sccidx[MAX_LEN][COLOR_LEN];
int dp[1 << COLOR_LEN][MAX_LEN];
int V;

int solved(int state, int prev, int cur) {
	if (cur == V) return 0;
	if (dp[state][cur] != -1) return dp[state][cur];

	int& ret = dp[state][cur];
	ret = INF;

	for (int i = 0; i < COLOR_LEN; i++) {
		if (state & (1 << i)) continue;

		state &= ~prev;
		ret += min(ret, solved(state | (1 << i), 1 << i, cur + 1) + sccidx[cur][i]);
	}

	return dp[state][cur];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	for (int i = 0; i < V; i++) {
		cin >> sccidx[i][RED] >> sccidx[i][GREEN] >> sccidx[i][BLUE];
	}

	// start house color red	(1 << 0) + (1 << 1) && (1 << 0) + (1 << 2)
	// start house color green	(1 << 1) + (1 << 0) && (1 << 1) + (1 << 2)
	// start house color blue	(1 << 2) + (1 << 0) && (1 << 2) + (1 << 1)

	memset(dp, -1, sizeof(dp));
	// next blue
	cout << solved((1 << RED) + (1 << GREEN), (1 << RED), 1) << "\n";
	cout << solved((1 << RED) + (1 << GREEN), (1 << GREEN), 1) << "\n";
	// next green
	cout << solved((1 << RED) + (1 << BLUE), (1 << RED), 1) << "\n";
	cout << solved((1 << RED) + (1 << BLUE), (1 << BLUE), 1) << "\n";
	// next red
	cout << solved((1 << GREEN) + (1 << BLUE), (1 << GREEN), 1) << "\n";
	cout << solved((1 << GREEN) + (1 << BLUE), (1 << BLUE), 1) << "\n";
	

	return 0;
}