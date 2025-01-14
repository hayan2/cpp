#define MOD_LEN 104
#define MAX_LEN 16
#define all(x) (x).begin(), (x).end()
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

string element[MAX_LEN];
int cache[MAX_LEN];
int dp[1 << MAX_LEN][MOD_LEN];
int N, K, cnt = 0;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int factorial(int x) {
	if (x == 1) return 1;
	return x * factorial(x - 1);
}

int getDigits(int x) {
	int denominator = 10, tmp = x;

	while (x > denominator) denominator *= 10;

	return denominator;
}

int solved(int state, int remainder) {
	if (state == (1 << N) - 1) return (remainder == 0);	

	int& ret = dp[state][remainder];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) {
			int digit = getDigits(cache[i]);

			ret += solved(state | (1 << i), (remainder * digit + cache[i]) % K);
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> element[i];
	}

	cin >> K;

	// scaled
	for (int i = 0; i < N; i++) {
		string x = element[i];
		int len = x.length();
		int idx = 0, tmp = 0;

		while (len != idx) {
			tmp *= 10;
			tmp += x[idx++] - '0';
			tmp %= K;
		}

		cache[i] = tmp;
	}

	memset(dp, -1, sizeof(dp));
	int res = solved(0, 0);
	int d = factorial(N);
	int g = gcd(d, res);

	cout << res / g << "/" << d / g;

	return 0;
}