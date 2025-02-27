#include <iostream>
#include <algorithm>

#define MOD 1000000003
#define MAX_LEN 1001

using namespace std;

int dp[MAX_LEN][MAX_LEN];
int V, N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> V >> N;

	for (int i = 0; i <= V; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	dp[1][1] = 0;
	for (int i = 2; i <= V; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;			
		}		
	}

	cout << dp[V][N] % MOD;

	return 0;
}