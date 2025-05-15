#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

const double INF = 1e9 + 7;
const int MAX_SIZE = 21;

typedef struct Point {
	double x, y;

	void read() { cin >> x >> y; }
}Point;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int T, N;

	cin >> T;

	while (T--) {
		Point p[MAX_SIZE] = { { 0, 0 }, };		
		double res = INF, x = 0, y = 0;

		cin >> N;		
		vector<int> c(N, 1);

		for (int i = 0; i < N; i++) p[i].read();
		for (int i = 0; i < N / 2; i++) c[i] = 0;
		do {
			x = y = 0;
			for (int i = 0; i < N; i++) {
				if (!c[i]) x += p[i].x, y += p[i].y;
				else x -= p[i].x, y -= p[i].y;
			}
			res = min(res, sqrt(pow(x, 2) + pow(y, 2)));
		} while (next_permutation(c.begin(), c.end()));

		printf("%.10f\n", res);
	}

	return 0;
}