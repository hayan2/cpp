#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char x;
	int res = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> x;
			if (x == 0x46) {
				if (!(i & 1) && !(j & 1)) res++;
				if ((i & 1) && (j & 1)) res++;
			}
		}
	}

	cout << res;

	return 0;
}