#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define INF 1e9

typedef pair<ll, ll> pll;

vector<pll> cache;
ll N, M, s, e, res = 0, low = -INF, high = -INF;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	res = M;

	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		if (s - e > 0) cache.push_back({ e, s });		
	}

	sort(cache.begin(), cache.end());

	for (pll cur : cache) {
		if (high < cur.first) {
			res += (high - low) * 2;

			low = cur.first;
			high = cur.second;
		}
		else high = max(high, cur.second);
	}
	res += (high - low) * 2;

	cout << res;

	return 0;
}
// //