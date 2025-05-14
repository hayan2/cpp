#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 10;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;

	cin >> T;

	while (T--) {
		cin >> a >> b;
		int res = 1;
		for (int i = 0; i < b; i++) res = (res * a) % 10;
		(!res) ? cout << "10\n" : cout << res << "\n";
	}

	return 0;
}