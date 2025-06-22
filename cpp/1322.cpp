#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull X, K;
	cin >> X >> K;

	ull Y = 0, pos = 0;

	while (K > 0) {
		if (!((X >> pos) & 1)) {
			if ((K & 1) == 1) Y |= (1LL << pos);
			K >>= 1;
		}
		pos++;
	}

	cout << Y;

	return 0;
}