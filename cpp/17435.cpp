#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Time Limit Exceeded

int E, Q, a, s;

void solved(vector<int> cache) {
	while (Q--) {
		cin >> a >> s;

		while (a--) s = cache[s];

		cout << s << endl;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> E;
	vector<int> cache(E + 1, 0);

	for (int i = 1; i <= E; i++) {
		cin >> cache[i];
	}

	cin >> Q;

	solved(cache);

	return 0;
}