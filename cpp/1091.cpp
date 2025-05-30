#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int MAX_SIZE = 51;

set<vector<int>> s;
vector<int> P, S, cache;
int N, cnt = 0;

bool cmp() {
	for (int i = 0; i < N; i++) 
		if (P[cache[i]] != (i % 3)) return false;
	return true;
}

void shuffle() {
	if (cmp()) {
		cout << cnt;
		return;
	}

	vector<int> tmp(N + 1);
	for (int i = 0; i < N; i++)
		tmp[S[i]] = cache[i];
	cache = tmp;

	if (s.find(cache) != s.end()) {
		cout << -1;
		return;
	}
	s.insert(cache);
	cnt++;

	shuffle();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	P.resize(N + 1);
	S.resize(N + 1);
	cache.resize(N + 1);
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) { cin >> S[i]; cache[i] = i; }

	shuffle();

	return 0;
}