#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int s, N, K, R1, R2, C1, C2;

int solved(int n, int x, int y) {
	if (n == 1) return 0;
	int len = n / N;
	if (x >= len * (N - K) / 2 && x < len * (N + K) / 2 &&
		y >= len * (N - K) / 2 && y < len * (N + K) / 2)
		return 1;
	return solved(len, x % len, y % len);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int n = pow(N, s);
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			cout << solved(n, i, j);
		}
		cout << "\n";
	}

	return 0;
}