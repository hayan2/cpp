#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;
const int MAX_EDGE = 100001;
const int MAX_VTX = 1001;

int T, N, K, u, v, w;

void solved(vector<int> edge[MAX_VTX], vector<int>& dp, vector<int>& cache, vector<int>& indegree, int cur) {
	for (auto nxt : edge[cur]) {
		dp[nxt] = max(dp[nxt], dp[cur] + cache[nxt]);
		if (!(--indegree[nxt])) solved(edge, dp, cache, indegree, nxt);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	while (T--) {
		cin >> N >> K;
		vector<int> edge[MAX_VTX];
		vector<int> cache(N + 1), indegree(N + 1), dp(N + 1);
		for (int i = 1; i <= N; i++) cin >> cache[i];
		for (int i = 0; i < K; i++) {
			cin >> u >> v;
			edge[u].push_back(v);
			indegree[v]++;
		}
		cin >> w;
				
		for (int i = 1; i <= N; i++) {
			if (!indegree[i]) {
				if (!dp[i]) dp[i] = cache[i];
				solved(edge, dp, cache, indegree, i);				
			}
		}
		

		cout << dp[w] << "\n";
	}
	
	return 0;
}