#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1e9

typedef pair<int, int> pii;

vector<pii> cache;
int N, s, e, res = 0, low = -INF, high = -INF;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << INF;
	cin >> N;

	for (int i = 0; i < N; i++) {		
		cin >> s >> e;
		cache.push_back({ s, e });
	}

	sort(cache.begin(), cache.end());
	
	for (int i = 0; i < N; i++) {
		if (high < cache[i].first) {
			res += high - low;

			low = cache[i].first;
			high = cache[i].second;
		}
		else high = max(high, cache[i].second);
	}
	res += high - low;

	cout << res;

	return 0;
}