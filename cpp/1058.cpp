#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int MAX_N = 51;

string cache[MAX_N];
int visited[MAX_N][MAX_N] = { 0, };
int dp[MAX_N] = { 0, };
int N;

void solve(int r, int c) {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) cin >> cache[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) solve(i, j);
		}
	}

	return 0;
}