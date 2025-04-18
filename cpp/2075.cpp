#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1507;

int cache[MAX_N * MAX_N];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int N, res = 0;

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> cache[i];
	}

	sort(cache, cache + N * N);

	cout << cache[N * N - N];

	return 0;
}