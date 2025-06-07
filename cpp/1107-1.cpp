#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

vector<char> cache;
int N, M, x;

int getDigits(int x, int d) {
	if (x >= 10) getDigits(x / 10, d + 1);
	else return d;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		char n; cin >> n;
		cache.push_back(n);
	}
	int res = 1000001;
	for (int i = 0; i < 1000000; i++) {
		string cur = to_string(i);
		bool flag = true;
		for (int j = 0; j < cache.size(); j++) {
			if (cur.find(cache[j]) != string::npos) {
				flag = false;
				break;
			}
		}		
		if (flag) {
			if (res > abs(N - i)) {
				res = abs(N - i);
				x = i;
			}
		}
		if (res < abs(N - i)) break;
	}

	res = min(res + getDigits(x, 1), abs(N - 100));
	cout << res;

	return 0;
}