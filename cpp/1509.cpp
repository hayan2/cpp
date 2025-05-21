#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int MAX_SIZE = 2501;
const int INF = 1e9;

bool root[MAX_SIZE][MAX_SIZE];
string str;
int len = 0, dp[MAX_SIZE] = { 0, };


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (len = 1; str[len] != NULL; len++); len--;

	for (int i = 1; i <= len; i++) root[i][i] = true;
	for (int i = 1; i < len; i++) {
		if (str[i] == str[i + 1]) root[i][i + 1] = true;
	}
	for (int i = 3; i <= len; i++) {
		for (int low = 1; low + i - 1 <= len; low++) {
			int high = low + i - 1;
			if (str[low] == str[high] && root[low + 1][high - 1]) root[low][high] = true;
		}
	}
	
	for (int i = 1; i <= len; i++) {
		dp[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (root[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}

	cout << dp[len];

	return 0;
}