#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

int cache[10] = { 0, };
int N, M;

bool isBroken(int x) {
	string cur = to_string(x);
	for (int i = 0; i < cur.length(); i++) {
		if (cache[cur[i] - '0']) return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n; cin >> n;
		cache[n] = 1;
	}

	int res = abs(N - 100);
	for (int i = 0; i < 1000001; i++) {
		if (isBroken(i)) continue;
		int x = abs(N - i) + to_string(i).length();
		res = min(res, x);
	}

	cout << res;

	return 0;
}