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

	int N, k;
	cin >> N >> k;
	
	int d = 9;
	
	for (int i = 2; i < 9; i++) {
		if (k >= d) break;
	}

	return 0;
}