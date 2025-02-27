#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_LEN 500001
#define MAX_LOG 19

int sccidx[MAX_LOG][MAX_LEN];
int m, Q, N, x;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;

	for (int i = 1; i <= m; i++) {
		// 2^0
		cin >> sccidx[0][i];
	}

	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= m; j++) {
			sccidx[i][j] = sccidx[i - 1][sccidx[i - 1][j]];
		}
	}

	cin >> Q;

	while (Q--) {
		cin >> N >> x;

		for (int i = MAX_LOG - 1; i > -1; i--) {
			int cur = (1 << i);

			if (N >= cur) {
				x = sccidx[i][x];
				N -= cur;
				if (!N) break;
			}
		}

		cout << x << "\n";
	}

	return 0;
}