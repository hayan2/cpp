#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 300001;
using ll = long long;
typedef pair<int, int> pii;

priority_queue<int> pq;
ll res = 0;
int N, K, w, c, idx = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	vector<pii> cache(N);
	vector<int> pack(K);

	for (int i = 0; i < N; i++) {
		cin >> w >> c;

		cache[i] = { w, c };
	}	
	for (int i = 0; i < K; i++) cin >> pack[i];

	sort(cache.begin(), cache.end());
	sort(pack.begin(), pack.end());

	for (auto x : pack) {
		while (idx < N && cache[idx].first <= x) pq.push(cache[idx++].second);
		if (!pq.empty()) res += (ll)pq.top(), pq.pop();
	}

	cout << res;

	return 0;
}