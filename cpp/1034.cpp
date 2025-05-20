#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> cache;
	vector<string> key;
	int N, M, K, res = 0;

	cin >> N >> M;
	 
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		cache[s]++;
	}
	cin >> K;

	for (const auto& cur : cache) {
		string s = cur.first;
		int cnt = 0;
		for (auto x : s) 
			if (x == '0') cnt++;
		if (cnt <= K && ((cnt & 1) == (K & 1))) res = max(res, cur.second);
	}

	cout << res;

	return 0;
}