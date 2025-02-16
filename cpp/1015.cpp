#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> type;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x;

	cin >> N;
	
	vector<type> cache;

	for (int i = 0; i < N; i++) {
		cin >> x;
		cache.push_back({ x, i });
	}

	sort(cache.begin(), cache.end());

	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		res[cache[i].second] = i;
	}

	for (auto cur : res) {
		cout << cur << " ";
	}

	return 0;
}