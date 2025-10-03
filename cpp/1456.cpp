#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int MAX_PRIME = 10000000;

vector<bool> cache(MAX_PRIME + 1, true);

void sieve() {	
	cache[0] = cache[1] = false;

	for (int i = 2; i * i <= MAX_PRIME; i++) {
		if (cache[i]) {
			for (int j = i * i; j <= MAX_PRIME; j += i) {
				cache[i] = false;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll A, B;

	cin >> A >> B;

	sieve();

	int cnt = 0;

	for (int i = 2; i <= MAX_PRIME; i++) {
		if (cache[i]) {
			ll n = i, x = 2;
			while (n <= B / i) {
				if (A <= n * i) cnt++;
				n *= i;
			}
		}
	}

	cout << cnt;

	return 0;
}