#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string dp[51];
int cost[51] = { 0, };
char c[11] = { '\0' };
int N, M, m = -1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		dp[c[i] - '0'] = max(c[i] - '0', (char(i) + '0'));
		cost[c[i] - '0'] = c[i] - '0';
		m = max(m, c[i] - '0');
	}
	cin >> M;

	for (int i = m + 1; i <= M; i++) {
		dp[i] = dp[i - 1];
		cost[i] = cost[i - 1];
		for (int j = 0; j < N; j++) {
			if (i - cost[i] <= c[j] - '0') {
				string tmp = char(j + '0') + dp[i - (c[j] - '0')];
				if (tmp.compare("\0")) {
					if (dp[i].length() == tmp.length()) {
						if ((dp[i][0] - '0') < tmp[0] - '0') {
							dp[i][0] = tmp[0] - '0';
							cost[i] = cost[i - (c[j] - '0')] + (c[j] - '0');
						}
					}
					else if (dp[i].length() < tmp.length()) {
						dp[i] = tmp;
						cost[i] = cost[i - (c[j] - '0')] + (c[j] - '0');
					}
				}				
			}
		}
	}

	cout << dp[M];

	return 0;
}