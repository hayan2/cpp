#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using ull = unsigned long long;

map<ull, ull> cache;

ull solved(ull x) {
	if (!x) return 0LL;
	if (cache.count(x)) return cache[x];
	return cache[x] = (x + 1) / 2 + 2 * solved(x / 2);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// (x & -x)
	ull A, B;
	cin >> A >> B;
	
	cout << solved(B) - solved(A - 1);

	return 0;
}