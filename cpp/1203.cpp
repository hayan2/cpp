#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const int MAX_N = 52;

double p[MAX_N] = { 0.0, };
double dp[MAX_N][MAX_N][2];
int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) cin >> p[i];

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			for (int k = 0; k < 2; k++) dp[i][j][k] = 0;
		}
	}

	dp[1][K][0] = 1.0;

	for (int len = 1; len <= N - 2; len++) {

	}

	return 0;
}