#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 1001;

vector<int> cache;
int N;

int gcd(int a, int b) {
	if (!b) return a;
	else return gcd(b, a % b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;

	cache.resize(N);

	for (int i = 0; i < N; i++) cin >> cache[i];

	sort(cache.begin(), cache.end());

	vector<int> r;

	for (int i = 1; i < N; i++) r.push_back(cache[i] - cache[i - 1]);

	int g = r[0];
	for (int i = 1; i < r.size(); i++) g = gcd(g, r[i]);

	cout << g;

	return 0;
}