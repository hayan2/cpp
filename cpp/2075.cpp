#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1507;

int root[MAX_N * MAX_N];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int N, res = 0;

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> root[i];
	}

	sort(root, root + N * N);

	cout << root[N * N - N];

	return 0;
}//