#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, b;
	cin >> x >> b;

	if (x == 0) {
		cout << 0 << endl;
		return 0;
	}

	string res = "";

	if (b > 0) {
		if (x < 0) {
			cout << "-";
			x = -x;
		}
		while (x > 0) {
			int rem = x % b;
			res += to_string(rem);
			x /= b;
		}
	}
	else {
		while (x != 0) {
			int rem = x % b;
			x /= b;

			if (rem < 0) {
				rem -= b;
				x++;
			}
			res += to_string(rem);
		}
	}

	reverse(res.begin(), res.end());
	cout << res;

	return 0;
}