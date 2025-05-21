#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_SIZE = 1007;

int root[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];
int N, w;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> w;
	//
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < w; j++)	cin >> root[i][j];
	dp[0][0] = root[0][0];
	for (int i = 1; i < w; i++) dp[0][i] = dp[0][i - 1] + root[0][i];

	for (int i = 1; i < N; i++) {
		vector<int> l(w), r(w);

		l[0] = dp[i - 1][0] + root[i][0];
		for (int j = 1; j < w; j++) l[j] = max(l[j - 1], dp[i - 1][j]) + root[i][j];

		r[w - 1] = dp[i - 1][w - 1] + root[i][w - 1];
		for (int j = w - 2; j > -1; j--) r[j] = max(r[j + 1], dp[i - 1][j]) + root[i][j];

		for (int j = 0; j < w; j++) dp[i][j] = max(l[j], r[j]);
	}

	cout << dp[N - 1][w - 1];

	return 0;
}