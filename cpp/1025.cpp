#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;
using ll = long long;
const int MAX_SIZE = 10;

vector<string> cache;
int N, M, res = -1;

bool isPerfectSquare(int n) { return sqrt(n) == (int)sqrt(n); }

void solved(int x, int y, string val, int xd, int yd) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;

	val += cache[x][y];

	if (!val.empty()) {
		int cur = stoi(val);
		if (isPerfectSquare(cur)) res = max(res, cur);
	}

	solved(x + xd, y + yd, val, xd, yd);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cache.resize(N, "");
	for (int i = 0; i < N; i++) cin >> cache[i];

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			for (int xd = -N + 1; xd < N; xd++) {
				for (int yd = -M + 1; yd < M; yd++) {
					if (xd == 0 && yd == 0) continue;
					solved(x, y, "", xd, yd);
				}
			}
		}
	}

	cout << res;

	return 0;
}