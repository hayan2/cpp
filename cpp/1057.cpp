#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b, res = 0;

	cin >> N >> a >> b;

	while (a != b) {
		a++, b++;
		a /= 2;
		b /= 2;
		res++;
	}

	cout << res;

	return 0;
}