#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 1;

bool rem[MAX_N] = { false, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int r = 0, i = 1;

	while (true) {
		r = (r * 10 + 1) % N;

		if (rem[r]) {
			cout << "-1";
			break;
		}
		if (!r) {
			cout << i;
			break;
		}

		rem[r] = true;
		i++;
	}

	return 0;
}