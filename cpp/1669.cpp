#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll X, Y;

	cin >> X >> Y;

	ll D = Y - X;
	if (!D) {
		cout << "0";

		return 0;
	}

	ll m = (ll)ceil(sqrt((double)D));
	
	if (D <= (m * m) - m) cout << 2 * m - 2;
	else cout << 2 * m - 1;

	return 0;
}