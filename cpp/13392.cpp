#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10001;

string str, root;
int dp[MAX_SIZE][10], N;

int solved(int n, int s) {
	if (n == N) return 0;
	if (dp[n][s] != -1) return dp[n][s];

	int x = ((str[n] - '0' + s) % 10 - (root[n] - '0') + 10) % 10;	
	return dp[n][s] = min(solved(n + 1, s) + x, solved(n + 1, (s + 10 - x) % 10) + 10 - x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> str >> root;
	memset(dp, -1, sizeof dp);

	cout << solved(0, 0);

	return 0;
}