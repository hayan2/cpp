#include <iostream>
#include <string>

using namespace std;

int n, i, f;
string s, a;

void solve() {
	cin >> s;
	a = s;
	n = a.size();
	string p(n, '9');
	if (a == p) {
		for (i = 0; i < n; i++) a[i] = '0';
		a[0] = '1', a += '0', n++;
		s.insert(s.begin(), '0');
	}
	for (i = n - 1; i >= n / 2; i--) a[i] = a[n - i - 1];
	for (i = 0; i < n; i++)
		if (a[i] != s[i]) {
			f = a[i] > s[i];
			break;
		}
	if (f) return;
	for (i = n / 2; i < n; i++) {
		if (i != n - i - 1) a[n - i - 1]++;
		if (a[i]++ != '9') break;
		a[i] = '0';
		if (i != n - i - 1) a[n - i - 1] = '0';
	}
	for (i = n - 1; i >= n / 2; i--) a[i] = a[n - i - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	cout << a << endl;

	return 0;
}