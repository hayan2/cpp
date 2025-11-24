#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const int MAX_N = 100001;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> mn(3), mx(3);
	int N, a, b, c;
	cin >> N;
	
	cin >> a >> b >> c;
	mn[0] = mx[0] = a;
	mn[1] = mx[1] = b;
	mn[2] = mx[2] = c;

	for (int i = 1; i < N; i++) {
		vector<int> curMin(3), curMax(3);
		int na, nb, nc;
		cin >> na >> nb >> nc;
		//
		curMax[0] = max(mx[0], mx[1]) + na;
		curMin[0] = min(mn[0], mn[1]) + na;
		curMax[1] = max({ mx[0], mx[1], mx[2] }) + nb;
		curMin[1] = min({ mn[0], mn[1], mn[2] }) + nb;
		curMax[2] = max(mx[1], mx[2]) + nc;
		curMin[2] = min(mn[1], mn[2]) + nc;

		mn = curMin;
		mx = curMax;
	}

	cout << max({ mx[0], mx[1], mx[2] }) << " " << min({ mn[0], mn[1], mn[2] });

	return 0;
}