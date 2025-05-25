#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, r, c, cnt = 0;

void solved(int x, int y, int s) {	
	if (r == x && c == y) {
		cout << cnt;
		return;
	}
	if (r >= x && c >= y && r < x + s && c < y + s) {
		solved(x, y, s / 2);
		solved(x, y + s / 2, s / 2);
		solved(x + s / 2, y, s / 2);
		solved(x + s / 2, y + s / 2, s / 2);
	}
	else cnt += s * s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	solved(0, 0, pow(2, N));

	return 0;
}