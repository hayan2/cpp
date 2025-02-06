#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Time Limit Exceeded

int M, Q, a, b;

void solved(vector<int> cache) {
	while (Q--) {
		cin >> a >> b;

		while (a--) b = cache[b];

		cout << b << endl;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	vector<int> cache(M + 1, 0);

	for (int i = 1; i <= M; i++) {
		cin >> cache[i];
	}

	cin >> Q;

	solved(cache);

	return 0;
}