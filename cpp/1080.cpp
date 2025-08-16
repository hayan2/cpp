#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 51;

int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];
int N, M;

int rev(int r, int c) {
	if (r + 3 > N || c + 3 > M) return 0;
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			cache[i][j] = (cache[i][j]) ? 0 : 1;
		}
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &A[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &B[i][j]);

			if (A[i][j] ^ B[i][j]) cache[i][j] = 1;
			else cache[i][j] = 0;
		}
	}

	int res = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (cache[i][j]) {
				if (rev(i, j)) res++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cache[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << res;

	return 0;
}