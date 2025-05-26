#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <regex>

using namespace std;
using pii = pair<int, int>;

map<int, pii> m;
vector<string> str;
vector<pii> c;
int N, K, res = 0;

bool cmp(pii a, pii b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (K < 5) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		s = regex_replace(s, regex("[acnti]+"), "");
		str.push_back(s);
	}

	for (auto cur : str) {
		int tmp = 0, cnt = 0;
		for (int i = 0; i < cur.size(); i++) {
			if (!(tmp & (1 << (cur[i] - 'a')))) {
				tmp |= (1 << (cur[i] - 'a'));
				cnt++;
			}
		}
		if (cnt <= K - 5) {
			for (auto& x : m) {
				if (x.first & tmp) {
					if (x.second.second < cnt) {
						swap(m[tmp], x.second);
						m.erase(x.first);
						break;
					}
				}
			}
			m[tmp].first++;
			m[tmp].second = cnt;
		}
	}

	for (auto& x : m)
		c.push_back({ x.second.first, x.second.second });
	sort(c.begin(), c.end(), &cmp);
	for (auto x : c) {
		cout << x.first << " " << x.second << "\n";
	}
	K -= 5;
	for (auto x : c) {
		if (K - x.second >= 0) {
			res += x.first;
			K -= x.second;
		}
	}

	cout << res;

	return 0;
}