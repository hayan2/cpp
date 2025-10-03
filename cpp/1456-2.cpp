#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int SIEVE_LIMIT = 1e7;

bool cache[SIEVE_LIMIT];
ll A, B;

void sieve() {
	cache[0] = cache[1] = false;
	
	for (int i = 2; i < SIEVE_LIMIT; i++) cache[i] = true;
	for (int i = 2; i * i <= SIEVE_LIMIT; i++) {
		if (cache[i]) {
			for (int j = i * i; j < SIEVE_LIMIT; j += i) {
				cache[j] = false;
			}
		}
	}
}

int solve() {
	int ret = 0;

	for (int i = 2; i <= SIEVE_LIMIT; i++) {
		if (cache[i]) {
			ll n = i;
			while (n <= B / i) {
				if (A <= n * i) ret++;
				n *= i;
			}
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B;

	sieve();
	cout << solve();

	return 0;
}