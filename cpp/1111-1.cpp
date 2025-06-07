#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 51;

int cache[MAX_SIZE];
int N, a = 0, b = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> cache[i];
		
	if (N == 1) {
		cout << "A";
		return 0;
	}
	else if (N == 2) {
		if (cache[0] == cache[1]) cout << cache[1];
		else cout << "A";
		return 0;
	}
	else {
		if (cache[1] - cache[0]) 
			a = (cache[2] - cache[1]) / (cache[1] - cache[0]);
		b = cache[1] - cache[0] * a;

		for (int i = 0; i < N - 1; i++) {
			if (cache[i + 1] != cache[i] * a + b) {
				cout << "B";
				return 0;
			}
		}
	}
	
	cout << cache[N - 1] * a + b;

	return 0;
}