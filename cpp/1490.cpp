#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

vector<int> cache;
ll N;

string solve(string s) {
	queue<string> q;

	q.push(s);

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		bool flag = true;
		ll tmp = stoll(cur);

		for (auto x : cache) {
			if (tmp % x) {
				flag = false;
				break;
			}
		}

		if (flag) return cur;

		for (char c = '0'; c <= '9'; c++) q.push(cur + c);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	ll tmp = N;

	while (tmp > 0) {
		if (tmp % 10) cache.push_back(tmp % 10);
		tmp /= 10;
	}

	cout << solve(to_string(N));

	return 0;
}
