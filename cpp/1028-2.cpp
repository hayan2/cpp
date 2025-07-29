#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_SIZE = 755;

int dl[MAX_SIZE][MAX_SIZE], dr[MAX_SIZE][MAX_SIZE];

int main(void) {
	int R, C;

	cin >> R >> C;

	char cache;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> cache;
			if (cache == '0') {
				dl[i][j] = 0;
				dr[i][j] = 0;
			}
			else {
				dl[i][j] = 1;
				dr[i][j] = 1;
			}
		}

	for (int i = R - 2; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (dl[i][j] && j != 0) {
				dl[i][j] += dl[i + 1][j - 1];
			}
			if (dr[i][j] && j != C - 1) {
				dr[i][j] += dr[i + 1][j + 1];
			}
		}
	}

	int res = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dl[i][j] != 0 && dr[i][j] != 0) {
				res = max(res, 1);
				if (dl[i][j] != 1 && dr[i][j] != 1) {
					int n = min(dl[i][j], dr[i][j]);
					while (n > 1) {
						if (dr[i + n - 1][j - n + 1] >= n && dl[i + n - 1][j + n - 1] >= n) {
							res = max(res, n);
						}
						n--;
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}