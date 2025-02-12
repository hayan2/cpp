#define ll long long
#define ld long double
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Coor {
	ll x, y;

	void read() { cin >> x >> y; };
}Coordinate;

ll getDistance(Coor p1, Coor p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

ll ccw(Coor p1, Coor p2, Coor p3) {
	long long ans = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

	if (ans < 0) return 1;
	else if (ans > 0) return -1;
	else return 0;
}

int main(void) {
	Coor p1, p2, p3, p4;

	p1.read(), p2.read(), p3.read(), p4.read();

	ll abc = ccw(p1, p2, p3);
	ll abd = ccw(p1, p2, p4);
	ll cda = ccw(p3, p4, p1);
	ll cdb = ccw(p3, p4, p2);


	if ((abc * abd < 0) && (cda * cdb < 0)) {
		ld a, b, c, d;
		ld resX, resY;

		if (p1.x == p2.x) {
			resX = p1.x;
			resY = (p4.y - p3.y) * (resX - p3.x) / (p4.x - p3.x) + p3.y;
		}
		else if (p3.x == p4.x) {
			resX = p3.x;
			resY = (p2.y - p1.y) * (resX - p1.x) / (p2.x - p1.x) + p1.y;
		}
		else {
			a = ((ld)(p2.y - p1.y)) / (p2.x - p1.x);
			b = ((ld)(p2.x * p1.y - p1.x * p2.y)) / (p2.x - p1.x);

			c = ((ld)(p4.y - p3.y)) / (p4.x - p3.x);
			d = ((ld)(p4.x * p3.y - p3.x * p4.y)) / (p4.x - p3.x);

			resX = (b - d) / (c - a);
			resY = a * (b - d) / (c - a) + b;
		}
		cout.precision(20);
		cout << "1\n" << resX << " " << resY;
	}
	else if (abc * abd * cda * cdb == 0) {
		if (abc * abd < 0 || cda * cdb < 0) {
			if (cda == 0) cout << "1\n" << p1.x << " " << p1.y;
			else if (cdb == 0) cout << "1\n" << p2.x << " " << p2.y;
			else if (abc == 0) cout << "1\n" << p3.x << " " << p3.y;
			else if (abd == 0) cout << "1\n" << p4.x << " " << p4.y;
		}
		else if ((abc == 0 && abd == 0) || (cda == 0 && cdb == 0)) {
			if ((getDistance(p2, p3) == 0 && getDistance(p1, p4) > getDistance(p3, p4))
				|| (getDistance(p2, p3) == 0 && getDistance(p1, p4) >= getDistance(p3, p4))) cout << "1\n" << p2.x << " " << p2.y;
			else if ((getDistance(p1, p3) == 0 && getDistance(p2, p4) > getDistance(p1, p2))
				|| (getDistance(p1, p4) == 0 && getDistance(p2, p3) > getDistance(p1, p2))) cout << "1\n" << p1.x << " " << p1.y;
			else if (max(getDistance(p1, p3), getDistance(p2, p3)) <= getDistance(p1, p2) || max(getDistance(p1, p4), getDistance(p2, p4)) <= getDistance(p1, p2)) cout << "1";
			else if (max(getDistance(p3, p1), getDistance(p4, p1)) <= getDistance(p3, p4) || max(getDistance(p3, p2), getDistance(p4, p2)) <= getDistance(p3, p4)) cout << "1";
			else cout << "0";
		}
		else if (getDistance(p2, p3) * getDistance(p2, p4) == 0)
			cout << "1\n" << p2.x << " " << p2.y;
		else if (getDistance(p1, p3) * getDistance(p1, p4) == 0)
			cout << "1\n" << p1.x << " " << p1.y;
		else cout << "0";
	}
	else cout << "0";
}