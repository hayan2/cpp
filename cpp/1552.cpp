#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

const int MAX_N = 7;
const int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char cache[MAX_N][MAX_N];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cache[i][j];
		}
	}

	vector<int> p(N);
	iota(p.begin(), p.end(), 0);

	int	mn = INF, mx = -INF;

	do {
		int cur = 1;

		for (int i = 0; i < N; i++) {
			if (cache[i][p[i]] >= '0' && cache[i][p[i]] <= '9') {
				cur *= (cache[i][p[i]] - '0');
			}
			else {
				cur *= -(cache[i][p[i]] - 'A' + 1);
			}
			
		}

		int cnt = 0;
		vector<bool> visited(N, false);

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				cnt++;
				int j = i;
				while (!visited[j]) {
					visited[j] = true;
					j = p[j];
				}
			}
		}

		int res = cur;
		if (cnt % 2 == 0) {
			res *= -1;
		}

		mn = min(mn, res);
		mx = max(mx, res);
	} while (next_permutation(p.begin(), p.end()));

	cout << mn << "\n" << mx;

	return 0;
}