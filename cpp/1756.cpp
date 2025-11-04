#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<int> oven;
vector<int> pizza;
int N, D;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> D >> N;
	oven.resize(D);
	pizza.resize(N);

	int o = INF;
	for (int i = 0; i < D; i++) cin >> oven[i];	
	for (int i = 0; i < D; i++) {
		o = min(o, oven[i]);	
		oven[i] = o;	
	}

	for (int i = 0; i < N; i++) cin >> pizza[i];

	int depth = D - 1;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		while (depth >= 0) {
			if (oven[depth] >= pizza[i]) {
				cnt++;
				depth--;
				break;
			}
			depth--;
		}
		if (depth < 0) {
			break;
		}
	}

	if (cnt < N) cout << 0;
	else cout << (depth + 1) + 1;

	return 0;
}