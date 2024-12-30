#define lli long long int
#define MOD 10000000
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

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

bool isOverlapped(Coordinate p1, Coordinate p2, Coordinate p3, Coordinate p4) {
	int l1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int l2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (!l1 && !l2) {
		if ((isStraight(p1, p2, p3) && isStraight(p1, p2, p4)) || (isStraight(p2, p1, p3) && isStraight(p2, p1, p4))) return false;
		else return true;
	}
	else return (l1 <= 0) && (l2 <= 0);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Coordinate p1, p2, p3, p4;

	p1.read(), p2.read(), p3.read(), p4.read();
	
	if (isOverlapped(p1, p2, p3, p4)) cout << "1";
	else cout << "0";

	return 0;
}