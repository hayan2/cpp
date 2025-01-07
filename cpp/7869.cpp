#define PI 3.14159265358979
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

double getAcos(double x) {
	if (x < -1.0) return PI;
	if (x > 1.0) return 0.0;
	return acos(x);
}

double solved(double x1, double y1, double r1, double x2, double y2, double r2) {
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	if (d >= r1 + r2) return 0.0;
	if (d <= abs(r1 - r2)) return PI * min(r1 * r1, r2 * r2);

	double theta1, theta2, sectorArea1, sectorArea2;

	theta1 = 2 * getAcos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
	theta2 = 2 * getAcos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

	sectorArea1 = 0.5 * r1 * r1 * (theta1 - sin(theta1));
	sectorArea2 = 0.5 * r2 * r2 * (theta2 - sin(theta2));

	return sectorArea1 + sectorArea2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double x1, y1, r1, x2, y2, r2;
	double res = 0.0;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	res = solved(x1, y1, r1, x2, y2, r2);
	
	cout << fixed;
	cout.precision(3);
	cout << round(res * 1000) / 1000;

	return 0;
}