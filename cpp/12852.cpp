#define MAX_LEN 1000001
#define INF 1e7
#include <iostream>
#include <algorithm>

using namespace std;

int cache[MAX_LEN];
int N;

// AC
// MEM 37056kb  |  TIME 32ms

int sol(int x) {
	if (x == 1) {
		return 0;
	}
	if (cache[x] != -1) {
		return cache[x];
	}

	cache[x] = sol(x - 1) + 1;
	if (x % 3 == 0) {
		cache[x] = min(cache[x], sol(x / 3) + 1);
	}
	if (x % 2 == 0) {
		cache[x] = min(cache[x], sol(x / 2) + 1);
	}
	
	return cache[x];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	fill_n(cache, N + 1, -1);
	cache[1] = 0;

	sol(N);

	cout << cache[N] << endl;

	while (N != 0) {
		if (N % 3 == 0 && cache[N / 3] == cache[N] - 1) {
			cout << N << " ";
			N /= 3;
		}
		else if (N % 2 == 0 && cache[N / 2] == cache[N] - 1) {
			cout << N << " ";
			N /= 2;
		}
		else {
			cout << N << " ";
			N -= 1;
		}
	}	

	return 0;
}