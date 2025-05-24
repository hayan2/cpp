#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
const int MAX_SIZE = 11;

typedef struct type {
	ll x, p, q;
}type;

vector<type> cache[MAX_SIZE];
ll res[MAX_SIZE] = { 0, };
ll N, a, b, p, q, l = 1, g;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}

void solved(int s) {
	queue<ll> q;

	q.push(s);
	res[s] = l;

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		for (auto nxt : cache[cur]) {
			if (res[nxt.x]) continue;
			res[nxt.x] = res[cur] * nxt.q / nxt.p;
			q.push(nxt.x);
		}
	}

	g = res[s];
	for (int i = 1; i < N; i++) g = gcd(g, res[i]);
	for (int i = 0; i < N; i++) cout << res[i] / g << " ";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;	

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;
		cache[a].push_back({ b, p, q });
		cache[b].push_back({ a, q, p });
		l *= lcm(p, q);
	}

	solved(0);

	return 0;
}