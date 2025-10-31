#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int INF = 1e9;
const int MAX_N = 300001;

vector<int> cache;
int dp[MAX_N];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) dp[i] = INF;
			
	int x = 0, r = 0;

	for (int i = 1; ; i++) {
		x += i;
		r += x;
		if (r > N) break;
		cache.push_back(r);
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int T : cache) {
			if (T > i) break;
			dp[i] = min(dp[i], dp[i - T] + 1);
		}
	}

	cout << dp[N];

	return 0;
}