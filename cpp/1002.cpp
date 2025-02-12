#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct Coor {
	double x, y, r;

	void read() { cin >> x >> y >> r; }
}Coor;

double getDistance(Coor p1, Coor p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	Coor p1, p2;

	cin >> T;

	while (T--) {
		p1.read(), p2.read();
		
		double d = getDistance(p1, p2);
		double s = p1.r > p2.r ? p1.r - p2.r : p2.r - p1.r;

		if (d == 0 && p1.r == p2.r) cout << "-1\n";
		else if (p1.r + p2.r == d || s == d) cout << "1\n";
		else if (s < d && d < (p1.r + p2.r)) cout << "2\n";
		else cout << "0\n";
	}

	return 0;
}