#define INF 1e9
#define MAX_LEN 1002
#define COLOR_LEN 3	
#define RED 0
#define GREEN 1
#define BLUE 2
#include <iostream>
#include <algorithm>

using namespace std;

int cache[MAX_LEN][COLOR_LEN];
int dp[1 << COLOR_LEN][MAX_LEN];
int N;

int solved(int state, int prev, int cur) {
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cache[i][RED] >> cache[i][GREEN] >> cache[i][BLUE];
	}

	// start house color red	(1 << 0) + (1 << 1) && (1 << 0) + (1 << 2)
	// start house color green	(1 << 1) + (1 << 0) && (1 << 1) + (1 << 2)
	// start house color blue	(1 << 2) + (1 << 0) && (1 << 2) + (1 << 1)

	

	return 0;
}