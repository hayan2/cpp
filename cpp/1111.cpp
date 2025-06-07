#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

int cache[MAX_SIZE];
int N, res = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> cache[i];

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		a = cache[i + 1] / cache[i];
		b = cache[i + 1] % cache[i];
		bool flag = true;

		for (int j = 0; j < N - 1; j++) {
			if (!(cache[j] * a + b == cache[j + 1])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			res = cache[N - 1] * a + b;
			break;
		}
	}

	cout << res;

	return 0;
}