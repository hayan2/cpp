#define lli double
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// WA?

typedef struct Coordinate {
	lli x, y;

	void read() { cin >> x >> y; }
}Coordinate;

int ccw(Coordinate p1, Coordinate p2, Coordinate p3) {
	lli ret = (p1.x * p2.y) + (p2.x * p3.y) + (p3.x * p1.y);
	ret -= (p1.x * p3.y) + (p2.x * p1.y) + (p3.x * p2.y);

	if (ret > 0) return 1;
	else if (!ret) return 0;
	else return -1;
}

bool isStraight(Coordinate p1, Coordinate p2, Coordinate p3) {
	if (p1.x < p2.x) return p2.x < p3.x;
	else if (p2.x < p1.x) return p3.x < p2.x;
	else {
		if (p1.y < p2.y) return p2.y < p3.y;
		else if (p2.y < p1.y) return p3.y < p2.y;
	}
}

bool isBetween(Coordinate p1, Coordinate p2, Coordinate p3) {
	return min(p1.x, p2.x) <= p3.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p3.y <= max(p1.y, p2.y);
}

Coordinate isOverlapped(Coordinate p1, Coordinate p2, Coordinate p3, Coordinate p4) {
	int l1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int l2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	lli A1 = p2.y - p1.y;
	lli B1 = p1.x - p2.x;
	lli C1 = (p2.y - p1.y) * p1.x + (p1.x - p2.x) * p1.y;	
	lli A2 = p4.y - p3.y;
	lli B2 = p3.x - p4.x;
	lli C2 = (p4.y - p3.y) * p3.x + (p3.x - p4.x) * p3.y;

	lli det = A1 * B2 - A2 * B1;
	lli x = 1, y = 1;
	if (det) {
		x = (B2 * C1 - B1 * C2) / det;
		y = (A1 * C2 - A2 * C1) / det;
	}	

	if (!l1 && !l2) {
		if ((isStraight(p1, p2, p3) && isStraight(p1, p2, p4)) || (isStraight(p2, p1, p3) && isStraight(p2, p1, p4))) return { 0, 0 };
		else {
			if (det == 0) {				
				if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) || (p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) {
					if (isBetween(p1, p2, p3)) return p3;
					if (isBetween(p1, p2, p4)) return p4;
					if (isBetween(p3, p4, p1)) return p1;
					if (isBetween(p3, p4, p2)) return p2;
					return { x, y };
				}
				return { 1, 1 };
			}
			return { x, y };  
		}
	}
	else {
		if ((l1 <= 0) && (l2 <= 0)) {
			if (det == 0) {				
				if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) || (p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) {
					if (isBetween(p1, p2, p3)) return p3;
					if (isBetween(p1, p2, p4)) return p4;
					if (isBetween(p3, p4, p1)) return p1;
					if (isBetween(p3, p4, p2)) return p2;
					return { x, y };
				}				
				return { 1, 1 };
			}
			
			return { x, y };
		}
		return { 0, 0 };
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Coordinate p1, p2, p3, p4;

	p1.read(), p2.read(), p3.read(), p4.read();

	Coordinate ret = isOverlapped(p1, p2, p3, p4);

	cout.precision(10);
	if (!ret.x && !ret.y) cout << "0";
	else {
		cout << "1\n";
		if (ret.x > 1 && ret.y > 1) cout << ret.x << " " << ret.y;
	}	

	return 0;
}