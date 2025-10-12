#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> cache;
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cache.resize(N);

	for (int i = 0; i < N; i++) cin >> cache[i];

	sort(cache.begin(), cache.end());

	if (N <= 2) {
		cout << N;

		return 0;
	}

	int l = 2;

	for (int i = 0; i < N; i++) {
		for (int j = i + 2; j < N; j++) {
			if (cache[i] + cache[i + 1] > cache[j]) {
				l = (l > j - i + 1) ? l : j - i + 1;
			}
		}
	}

	cout << l;

	return 0;
}