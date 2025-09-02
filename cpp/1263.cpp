#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;

bool cmp(pii& a, pii& b) {
	return a.second > b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T, S;

	cin >> N;
		
	vector<pii> cache(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> T >> S;

		cache.push_back({ T, S });
	}

	sort(cache.begin(), cache.end(), cmp);

	int s = 0, res = INF;
	for (int i = 0; i < N; i++) {
		s += cache[i].first;
		if (cache[i].second - s < 0) {
			cout << "-1";
			return 0;
		}
		res = min(res, cache[i].second - s);
	}

	cout << res;

	return 0;
}