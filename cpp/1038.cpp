#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;
const int MAX_SIZE = 1 << 21;

ll cache[MAX_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int N;

ll solved() {	
	if (N <= 10) return N;
	int idx = 10;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < cache[i] % 10; j++) {
			cache[idx] = cache[i] * 10 + j;
			idx++;
		}
	}
	return (cache[N]) ? cache[N] : -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << solved();

	return 0;
}