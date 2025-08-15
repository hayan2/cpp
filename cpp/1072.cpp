#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double X, Y;

	cin >> X >> Y;

	int wr = (Y * 100) / X;

	if (wr >= 99) {
		cout << "-1";
		return 0;
	}

	int low = 1, high = INF, res = INF;

	while (low <= high) {
		int mid = (low + high) / 2;
		int nwr = ((Y + mid) * 100) / (X + mid);

		if (nwr > wr) {
			res = min(res, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << res;

	return 0;
}