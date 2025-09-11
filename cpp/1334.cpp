#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

string solve(string s) {
	int n = s.length();
	int c = 1;

	for (int i = n - 1; i >= 0; i--) {
		int d = (s[i] - '0') + c;
		s[i] = (d % 10) + '0';
		c = d / 10;
		if (!c) break;
	}

	if (c > 0) return "1" + s;
	return s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int length = str.length();

	string half = str.substr(0, length / 2 + (length % 2));

	string l = half;
	string r = l;
	reverse(r.begin(), r.end());

	if (length % 2 != 0) r = r.substr(1);

	string p1 = l + r;

	if (p1 > str) cout << p1;	
	else {
		string nl = solve(half);
		string nr = nl;
		reverse(nr.begin(), nr.end());

		if (length % 2 != 0) nr = nr.substr(1);

		string p2 = nl + nr;
		cout << p2;
	}

	return 0;
}