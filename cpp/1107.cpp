#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;
const int MAX = 1000001;

int r[10];
int N, M, cnt = 0;

int getDigits(int x, int d) {
	if (x >= 10) getDigits(x / 10, d + 1);
	else return d;
}

int solved(int s, int d) {
	if (!d) return s;	

	int x = N / d;
	int cache = MAX, n = 0;
	for (int i = 0; i < 10; i++) {
		if (!r[i]) continue;
		if (abs(x - (s * 10 + i)) < cache) {
			cache = abs(x - (s * 10 + i));
			n = i;
		}
	}
	cnt++;
	solved(s * 10 + n, d / 10);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) r[i] = 1;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int n; cin >> n;
		r[n] = 0;
	}
	
	int res = solved(0, pow(10, getDigits(N, 0)));
	res = min(abs(res - N) + cnt, abs(N - 100));
	cout << res;

	return 0;
}