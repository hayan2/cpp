#define ull unsigned long long
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

ull n;
int posn, endn;
long long ans = 0;
bool fin = false;
string res = "";

void dfs(int idx) {
	if (fin) return;
	if (idx == endn) {
		if (stoll(res) <= n) {
			ans++;
		}
		else {
			fin = true;
		}
		return;
	}
	if (idx == 0) {
		for (int i = 1; i < 10; i++) {
			res[idx] = res[posn - idx - 1] = i + '0';
			dfs(idx + 1);
			if (fin) return;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			res[idx] = res[posn - idx - 1] = i + '0';
			dfs(idx + 1);
			if (fin) return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	posn = to_string(n).size();

	for (int i = 1; i < posn; i++) {
		ull tmp = 9;
		int endt = (i + 1) / 2;
		for (int j = 1; j < endt; j++) {
			tmp *= 10;
		}
		ans += tmp;
	}

	endn = (posn + 1) / 2;
	res.resize(posn, '0');

	dfs(0);

	cout << ans << '\n';
}