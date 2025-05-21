#include <iostream>
#include <algorithm>

using namespace std;

bool solved(int n, int k) {
	int cnt = 0;

	for (int i = 0; i < 25; i++) {
		if (cnt > k) return false;
		if ((n & (1 << i))) cnt++;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, cache;
	cin >> N >> K;
	cache = N;
	while (!solved(N, K) || cache > N) N++;
	cout << N - cache;

	return 0;
}