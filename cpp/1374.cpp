#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 100001;

vector<pii> cache;
int N;

int solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	
	pq.push(cache[0].second);

	for (int i = 1; i < N; i++) {
		int s = cache[i].first;
		int e = cache[i].second;

		int cur = pq.top();

		if (s >= cur) {
			pq.pop();
			pq.push(e);
		}
		else {
			pq.push(e);
		}
	}	

	return pq.size();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int x, s, e;

	cache.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x >> s >> e;

		cache[i] = { s, e };
	}

	sort(cache.begin(), cache.end());

	cout << solve();

	return 0;
}