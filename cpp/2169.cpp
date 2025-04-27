#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_SIZE = 1007;

int cache[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];
int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)	cin >> cache[i][j];
	dp[0][0] = cache[0][0];
	for (int i = 1; i < M; i++) dp[0][i] = dp[0][i - 1] + cache[0][i];

	for (int i = 1; i < N; i++) {
		vector<int> l(M), r(M);

		l[0] = dp[i - 1][0] + cache[i][0];
		for (int j = 1; j < M; j++) l[j] = max(l[j - 1], dp[i - 1][j]) + cache[i][j];

		r[M - 1] = dp[i - 1][M - 1] + cache[i][M - 1];
		for (int j = M - 2; j > -1; j--) r[j] = max(r[j + 1], dp[i - 1][j]) + cache[i][j];

		for (int j = 0; j < M; j++) dp[i][j] = max(l[j], r[j]);
	}

	cout << dp[N - 1][M - 1];

	return 0;
}