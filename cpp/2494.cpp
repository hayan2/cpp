#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 10001;

string str, cache;
int dp[MAX_SIZE][10], cnt[MAX_SIZE][10], N;

int solved(int n, int s) {
	if (n == N) return 0;
	if (dp[n][s] != -1) return dp[n][s];

	int x = ((str[n] - '0' + s) % 10 - (cache[n] - '0') + 10) % 10;
	int l = solved(n + 1, s) + x;
	int r = solved(n + 1, (s + 10 - x) % 10) + 10 - x;

	if (l < r) dp[n][s] = l, cnt[n][s] = -x;
	else dp[n][s] = r, cnt[n][s] = 10 - x;
	return dp[n][s];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> str >> cache;
	memset(dp, -1, sizeof dp);

	cout << solved(0, 0) << "\n";

	int s = 0;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << " " << cnt[i][s] << "\n";
		if (cnt[i][s] > -1) s = (s + cnt[i][s]) % 10;
	}

	return 0;
}