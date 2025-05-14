#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x, y;

	cin >> T;

	while (T--) {
		cin >> x >> y;
		int dist = y - x;
		double dsqrt = sqrt(dist);
		double r = round(dsqrt);

		(dsqrt > r) ? cout << r * 2 << "\n" : cout << r * 2 - 1 << "\n";
	}

	return 0;
}