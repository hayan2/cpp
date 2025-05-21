#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 51;

int root[MAX_SIZE][MAX_SIZE], r1, c1, r2, c2, m, s;

int main(void) {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int x = i - r1, y = j - c1;
			if (i - j < 0) {
				if (i + j < 0) root[x][y] = 4 * i * i + i + 1 - j;
				else root[x][y] = 4 * j * j - 3 * j + 1 - i;
			}
			else {
				if (i + j < 0) root[x][y] = 4 * j * j - j + 1 + i;
				else root[x][y] = 4 * i * i + 3 * i + 1 + j;
			}
			if (root[x][y] > m) m = root[x][y];
		}
	}
	for (; m; m /= 10) s++;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) printf("%*d ", s, root[i][j]);
		puts("");
	}
	return 0;
}
