#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X, res = 0;

	cin >> X;
	//
	while (X) {
		if (X & 1) res++;
		X >>= 1;
	}
	//
	cout << res;
	//
	return 0;
}