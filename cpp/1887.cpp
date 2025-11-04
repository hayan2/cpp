#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N;

	cin >> T >> N;

	vector<int> toppings(N);
	
	for (int i = 0; i < N; i++) {
		int ingre, t;
		cin >> ingre;

		while (ingre--) {
			cin >> t;
			
			toppings[i] |= (1 << (t - 1));
		}
	}


	int res = 0;
	for (int i = 0; i < (1 << T); i++) {
		for (int j = 0; j < N; j++) {
			if ((toppings[j] & i) == toppings[j]) break;
			if (j == N - 1) res++;
		}
	}

	cout << res;

	return 0;
}