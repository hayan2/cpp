#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int solved(int x, int y) {
	int n = max(abs(x), abs(y));
	int cache = (2 * n + 1);
	cache *= cache;

	int cst = 2 * n;
	if (x == n) return cache - (n - y);
	cache -= cst;
	if (y == -n) return cache - (n - x);
	cache -= cst;
	if (x == -n) return cache - (y + n);
	cache -= cst;
	return cache - (x + n);
}

int getValue(int x) { return x ? getValue(x / 10) + 1 : 0; }

int main() {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	int x = 0;
	for (int row = r1; row <= r2; row++)
		for (int col = c1; col <= c2; col++) x = max(x, getValue(solved(row, col)));

	for (int row = r1; row <= r2; row++) {
		for (int col = c1; col <= c2; col++) printf("%*d ", x, solved(row, col));
		puts("");
	}

}
