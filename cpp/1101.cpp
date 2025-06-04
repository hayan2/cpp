#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

int box[MAX_SIZE][MAX_SIZE], cache[MAX_SIZE] = { 0, }, color[MAX_SIZE] = { 0, };
int N, M, m = 0, idx = 0, c = 0, res = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x = 0;
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j]) x++, c = j;
		}
		if (x == 1) cache[i]++, color[c]++;
		else if (x > 1) cache[i] = -1;
		if (x >= m) idx = i, m = x;
	}

	if (m == 1) color[c]--;
	
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (cache[i] > 0) {
			for (int j = 0; j < M; j++) {
				if (color[j] > 1) res++, color[j]--;
			}
		}
		else if (cache[i] == -1) res++;
	}

	cout << res;

	return 0;
}