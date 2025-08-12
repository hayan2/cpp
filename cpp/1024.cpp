#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_L = 102;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;

	cin >> N >> L;

	for (int k = L; k < MAX_L; k++) {
		if (k == MAX_L - 1) {
			cout << "-1";
			break;
		}
		int cache = N - (k * (k - 1) / 2);

		if (!(cache % k) && cache > -1) {
			int tmp = cache / k;
			for (int i = tmp; i <= tmp + k - 1; i++) {
				cout << i << " ";
			}
			break;
		}

	}

	return 0;
}