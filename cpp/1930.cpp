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

int b1, s1, s2, s3, b2, s4, s5, s6;

bool solve() {
	if (b1 == b2) {
		return (s1 == s4 && s2 == s5 && s3 == s6) ||
			(s1 == s5 && s2 == s6 && s3 == s4) ||
			(s1 == s6 && s2 == s4 && s3 == s5);
	}
	else if (s1 == b2) {
		return (b1 == s4 && s2 == s5 && s3 == s6) ||
			(b1 == s5 && s2 == s6 && s3 == s4) ||
			(s2 == s4 && s3 == s5 && b1 == s6);
	}
	else if (s2 == b2) {
		return (b1 == s4 && s1 == s5 && s3 == s6) ||
			(b1 == s5 && s1 == s6 && s3 == s4) ||
			(b1 == s6 && s1 == s4 && s3 == s5);
	}
	else if (s3 == b2) {
		return (b1 == s4 && s1 == s5 && s2 == s6) ||
			(b1 == s5 && s1 == s6 && s2 == s4) ||
			(b1 == s6 && s1 == s4 && s2 == s5);
	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	while (K--) {
		cin >> b1 >> s1 >> s2 >> s3 >> b2 >> s4 >> s5 >> s6;

		cout << (solve() ? "1\n" : "0\n");
	}

	return 0;
}