#define lli long long int
#define MOD 10000000
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// WA

typedef struct Coordinate {
	lli x, y;
}Coordinate;

lli ccw(Coordinate p1, Coordinate p2, Coordinate p3) {
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

bool compare(Coordinate p1, Coordinate p2) {
	return (abs(p1.x) >= abs(p2.x) && abs(p1.y) >= abs(p2.y)) ? true : false;
}
 
void swap(Coordinate* p1, Coordinate* p2) {
	Coordinate tmp;
	tmp.x = p1->x;
	tmp.y = p1->y;
	p1->x = p2->x;
	p1->y = p2->y;
	p2->x = tmp.x;
	p2->y = tmp.y;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Coordinate p1, p2, p3, p4;

	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

	lli abc = ccw(p1, p2, p3);
	lli abd = ccw(p1, p2, p4);
	lli cda = ccw(p3, p4, p1);
	lli cdb = ccw(p3, p4, p2);
	
	lli l1 = abc * abd;
	lli l2 = cda * cdb;

	if (l1 < 0 && l2 < 0) cout << "1";
	else if (abc == 0 && abd == 0) {
		if (compare(p1, p2)) swap(&p1, &p2);
		if (compare(p3, p4)) swap(&p3, &p4);

		if (compare(p4, p1) && compare(p2, p3)) cout << "1";
		else cout << "0";
	}
	else if ((!l1 && l2 <= 0) || (l1 <= 0 && !l2)) cout << "1";
	else cout << "0";

	return 0;
}