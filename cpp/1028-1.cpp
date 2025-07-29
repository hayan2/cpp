#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_SIZE = 755;

int cache[MAX_SIZE][MAX_SIZE];
int ul[MAX_SIZE][MAX_SIZE] = { 0 };
int ur[MAX_SIZE][MAX_SIZE] = { 0 };
int dl[MAX_SIZE][MAX_SIZE] = { 0 };
int dr[MAX_SIZE][MAX_SIZE] = { 0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%1d", &cache[i][j]);
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cache[i][j]) {
				ul[i][j] = ul[i - 1][j - 1] + 1;
				ur[i][j] = ur[i - 1][j + 1] + 1;
			}
		}
	}

	for (int i = R; i > 0; i--) {
		for (int j = 1; j <= C; j++) {
			if (cache[i][j]) {
				dl[i][j] = dl[i + 1][j - 1] + 1;
				dr[i][j] = dr[i + 1][j + 1] + 1;
			}
		}
	}

	int res = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int k = min(ur[i][j], dr[i][j]);
			for (; k > res; k--) {
				int rc = j + 2 * (k - 1);
				if (rc <= C) {
					if (min(ul[i][rc], dl[i][rc]) >= k) {
						res = k;
						break;
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}