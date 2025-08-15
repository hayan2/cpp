#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	double x, y;

	void read() { cin >> x >> y; }
};

double getDistance(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Point A, B, C;

	A.read(), B.read(), C.read();

	if ((B.y - A.y) * (C.x - B.x) == (C.y - B.y) * (B.x - A.x)) {
		cout << "-1.0";
		return 0;
	}

	double ab = getDistance(A, B);
	double ac = getDistance(A, C);
	double bc = getDistance(B, C);

	double p1 = 2 * (ab + ac);
	double p2 = 2 * (ab + bc);
	double p3 = 2 * (ac + bc);

	cout.precision(16);
	cout.fixed;
	cout << max({ p1, p2, p3 }) - min({ p1, p2, p3 });
	
	return 0;
}