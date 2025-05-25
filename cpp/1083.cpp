#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

int cache[MAX_SIZE] = { 0, };
int N, S, l = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> cache[i];
	cin >> S;

	int s = 0;
	while (s < N && S > 0) {
		int idx = s;
		for (int i = s; i < ((N < s + S + 1) ? N : s + S + 1); i++)
			idx = (cache[idx] < cache[i]) ? i : idx;
		for (int i = idx; i > s; i--) {
			cache[i] ^= cache[i - 1] ^= cache[i] ^= cache[i - 1];
			S--;
		}
		s++;
	}
	
	for (int i = 0; i < N; i++) {
		cout << cache[i] << " ";
	}

	return 0;
}