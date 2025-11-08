#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

bool solve(string str) {	
	if (str.length() == 1) return true;

	int len = str.length();
	int mid = len / 2;

	string l = str.substr(0, mid);
	string r = str.substr(mid + 1);
	string p = r;

	reverse(r.begin(), r.end());
	for (char& c : r) c = (c == '0' ? '1' : '0');

	if (l != r) return false;

	return solve(p);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int T;
	cin >> T;

	while (T--) {
		cin >> str;

		cout << (solve(str) ? "YES\n" : "NO\n");
	}

	return 0;
}