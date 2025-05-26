#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAX_PRICE = 54;

string dp[MAX_PRICE];
int price[MAX_PRICE] = { 0, }, cost[MAX_PRICE] = { 0, };
int N, M, m = MAX_PRICE;

string maxstr(string a, string b) {
	if (a.length() < b.length()) return b;
	else if (a.length() > b.length()) return a;
	else {
		for (int i = 0; i < a.length(); i++) {
			if ((a[i] - '0') > (b[i] - '0')) return a;
			else if ((a[i] - '0') < (b[i] - '0')) return b;
		}
	}
	return a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i];		
		m = min(m, price[i]);
	}
	cin >> M;
	for (int i = 0; i < m; i++) dp[i] = "x";

	for (int i = m; i <= M; i++) {
		string tmp = "0";
		for (int j = N - 1; j > 0; j--) {
			if (i < price[j]) continue;
			int c = i - price[j];
			if (c < 0) continue;
			if (dp[c].front() == 'x') {
				tmp = maxstr(tmp, to_string(j));
				continue;
			}

			string nz = to_string(j);
			string z = to_string(j);
						
			for (int k = 0; k < c / price[0]; k++) {
				z += "0";
			}
			nz += dp[c];

			tmp = maxstr(tmp, maxstr(nz, z));
		}
		dp[i] = tmp;
	}

	cout << dp[M];

	return 0;
}