#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int s, N, K, r1, r2, c1, c2;

int solved(int n, int x, int y) {
	if (n == 1) return 0;
	int len = n / N;
	if (x >= len * (N - K) / 2 && x < len * (N + K) / 2 &&
		y >= len * (N - K) / 2 && y < len * (N + K) / 2) 
		return 1;	
	return solved(len, x % len, y % len);
}

int main() {
	int i, j;
	cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;
	if (s == 0) {
		cout << 0;
		return 0;
	}
	int len = 1;
	while (s--) len *= N;
	for (i = r1; i <= r2; i++) {
		for (j = c1; j <= c2; j++) {
			cout << solved(len, i, j);
		}
		cout << endl;
	}
}