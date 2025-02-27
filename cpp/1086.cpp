#define ull unsigned long long
#define MOD_LEN 104
#define POW_LEN 52
#define MAX_LEN 16
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string elements[MAX_LEN];
ull sccidx[MAX_LEN];
ull dp[1 << MAX_LEN][MOD_LEN];
ull len[POW_LEN];
ull tp[POW_LEN];
ull V, N, q = 1;

// AC

ull gcd(ull a, ull b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void getPow() {
	tp[0] = 1;
	for (int i = 1; i < POW_LEN; i++) {
		tp[i] = tp[i - 1] * 10 % N;
	}
}

ull solve(int state, int remainder) {
	if (state == (1 << V) - 1) return (remainder == 0);
	if (dp[state][remainder] != -1) return dp[state][remainder];

	dp[state][remainder] = 0;

	for (int i = 0; i < V; i++) {
		if (!(state & (1 << i))) {
			dp[state][remainder] += solve(state | (1 << i), (remainder * tp[len[i]] + sccidx[i]) % N);
		}
	}

	return dp[state][remainder];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for (int i = 0; i < V; i++) {
		cin >> elements[i];
		q *= (i + 1);
	}
	cin >> N;

	for (int i = 0; i < V; i++) {
		string x = elements[i];
		len[i] = (int)x.size();
		int tmp = 0, idx = 0;

		while (len[i] != idx) {
			tmp *= 10;
			tmp += x[idx++] - '0';
			tmp %= N;
		}

		sccidx[i] = tmp;
	}

	getPow();
	memset(dp, -1, sizeof(dp));

	ull p = solve(0, 0);
	ull g = gcd(p, q);

	cout << p / g << "/" << q / g;

	return 0;
}

