#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 2501;
const int INF = 1e9;

int dp[MAX_SIZE], len;
bool cache[MAX_SIZE][MAX_SIZE];
string str;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	len = str.size();
	str = " " + str;

	for (int i = 1; i <= len; i++) cache[i][i] = true;
	for (int i = 1; i < len; i++) {
		if (str[i] == str[i + 1]) cache[i][i + 1] = true;
	}
	for (int i = 3; i <= len; i++) {
		for (int low = 1; low + i - 1 <= len; low++) {
			int high = low + i - 1;
			if (str[low] == str[high] && cache[low + 1][high - 1]) cache[low][high] = true;
		}
	}
	
	for (int i = 1; i <= len; i++) {
		dp[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (cache[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}

	cout << dp[len];

	return 0;
}