#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_LEN 42

int cache[MAX_LEN] = { 0, 1, };
int T, N;

void getFibonacci(int n) {
	for (int i = 3; i < n; i++) cache[i] = cache[i - 1] + cache[i - 2];	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cache[1] = cache[2] = 1;
	getFibonacci(MAX_LEN);	
	
	cin >> T;

	while (T--) {
		cin >> N;

		if (!N) cout << "1 0\n";
		else if (N == 1) cout << "0 1\n";
		else cout << cache[N - 1] << " " << cache[N] << "\n";
	}

	return 0;
}