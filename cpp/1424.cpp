#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MOD = 13;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, C;

	cin >> N >> L >> C;

	int k = (C + 1) / (L + 1);
	int tmp = k;

	if (!(tmp % MOD)) tmp--;

	int res = (N + tmp - 1) / tmp;

	cout << res;

	return 0;
}