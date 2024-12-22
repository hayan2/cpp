#include <iostream>
#include <algorithm>

using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int res = CCW(x1, y1, x2, y2, x3, y3);

	(res > 0) ? cout << "1" : ((res == 0) ? cout << "0" : cout << "-1");

	return 0;
}