#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int ALPHABET = 26;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector<string> cache(N + 1);
	vector<ll> alpha(ALPHABET);

	for (int i = 0; i < N; i++) {
		int x = (i + 1) * (2 * N - i) + (i + N + 1) * (N - i);
		cin >> cache[i];

		for (int j = 0; j < cache[i].length(); j++) {
			int r = (j + 1) * (2 * M - j) + (j + M + 1) * (M - j);
			alpha[cache[i][j] - 'A'] += x * r;
		}
	}

	for (int i = 0; i < ALPHABET; i++) cout << alpha[i] << "\n";

	return 0;
}