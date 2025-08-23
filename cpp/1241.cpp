#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1000001;

int hits[MAX_N] = { 0, }, cnt[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> cache(N);	
	for (int i = 0; i < N; i++) {
		cin >> cache[i];
		cnt[cache[i]]++;
	}

	for (int i = 0; i < N; i++) {
		int cur = cache[i];
		int tot = 0;
		for (int j = 1; j * j <= cur; j++) {
			if (!(cur % j)) {
				tot += cnt[j];
				if (j * j != cur) {
					tot += cnt[cur / j];
				}
			}
		}
		hits[i] = tot - 1;
	}

	for (auto cur : cache) cout << hits[cur] << "\n";

	return 0;
}