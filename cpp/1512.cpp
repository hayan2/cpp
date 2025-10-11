#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	string str;

	cin >> M >> str;

	int res = INF;

	for (int i = 1; i <= M; i++) {
		int cnt = 0;

		for (int j = 0; j < i; j++) {
			map<char, int> m;
			int size = 0;

			for (int k = j; k < str.length(); k += i) {
				m[str[k]]++;
				size++;
			}

			int freq = 0;
			if (!m.empty()) {
				for (auto const& cur : m) {
					freq = max(freq, cur.second);
				}
			}

			cnt += (size - freq);
		}

		res = min(res, cnt);
	}
	cout << res;

	return 0;
}