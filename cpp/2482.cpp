#include <iostream>
#include <algorithm>

#define MOD 1000000003
#define MAX_LEN 1001
#define VISITED 1

using namespace std;

int visited[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int N, K;

int solved() {
	int cnt = 1, ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 2; j < N - 1; j++) {
			cnt++;
			if (cnt == K) {
				ret++;
				cnt = 1;
			}
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visited, 0, sizeof(visited));
	
	cin >> N >> K;

	cout << solved();

	return 0;
}