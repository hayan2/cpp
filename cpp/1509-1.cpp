#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

#define INF 1e9+7

using namespace std;

bool dp[2501][2501];
string str;
int N, cnt[2501];

bool is_palin(int st, int ed) {
	if (ed > N) return false;

	if (str[st] == str[ed]) {
		if (dp[st + 1][ed - 1] || ed - st == 1) {
			return true;
		}
	}
	return false;
}

void fill_dptable() {
	for (int d = 0; d < N; d++) {
		for (int i = 1; i + d <= N; i++) {
			if (d == 0) {
				dp[i][i] = true;
				continue;
			}
			if (is_palin(i, i + d)) {
				dp[i][i + d] = true;
			}
		}
	}
}

void solve() {
	fill_dptable();

	cnt[0] = 0;
	for (int i = 1; i <= N; i++) {
		cnt[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i]) {
				if (cnt[i] > cnt[j - 1] + 1) {
					cnt[i] = cnt[j - 1] + 1;
				}
			}
		}
	}
	cout << cnt[N];
}

int main() {
	cin >> str;
	N = str.size();
	str = " " + str;
	solve();

	return 0;
}
