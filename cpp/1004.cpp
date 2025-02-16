#include <iostream>
#include <algorithm>

using namespace std;

bool solved(int x, int y, int r, int x1, int y1, int x2, int y2) {
	return (((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r) && ((x - x2) * (x - x2) + (y - y2) * (y - y2) > r * r)
		|| ((x - x1) * (x - x1) + (y - y1) * (y - y1) > r * r) && ((x - x2) * (x - x2) + (y - y2) * (y - y2) < r * r));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, T;
	int res = 0;
	int x, y, r, x1, y1, x2, y2;

	cin >> T;

	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> n;
		res = 0;

		while (n--) {
			cin >> x >> y >> r;
			
			if (solved(x, y, r, x1, y1, x2, y2)) res++;
		}

		cout << res << '\n';
	}

	return 0;
}