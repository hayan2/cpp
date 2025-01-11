#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double X, Y, D, T;	

	cin >> X >> Y >> D >> T;
	
	double dist = sqrt(X * X + Y * Y);
	double res = 0;
	cout << fixed;
	cout.precision(9);

	if (D < T) cout << dist;
	else {
		res = dist;

		int jump = dist / D;
		dist -= jump * D;

		if (jump == 0) res = min(res, min(T + D - dist, 2.0 * T));
		else res = min(res, min(jump * T + dist, (jump + 1.0) * T));

		cout << res;
	}

	return 0;
}