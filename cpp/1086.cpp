#define MAX_LEN 16
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

string element[MAX_LEN];
int cache[MAX_LEN];
int dp[1 << MAX_LEN][MAX_LEN];
int N, K;

int solved(int remainder, int state) {
	if (state == (1 << N) - 1) return (remainder == 0);

	for (int i = 0; i < N; i++) {

	}
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

	int res = solved(0, 0);

	return 0;
}