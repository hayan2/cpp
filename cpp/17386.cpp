#define lli long long int
#define MOD 10000000
#include <iostream>
#include <algorithm>

using namespace std;

lli ccw(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3) {
	return ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) % MOD;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lli x1, y1, x2, y2, x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	lli l1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	lli l2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	(l1 < 0 && l2 < 0) ? cout << "1" : cout << "0";

	return 0;
}