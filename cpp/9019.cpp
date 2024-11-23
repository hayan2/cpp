#define MAX_LEN 10001
#define MOD 10000
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int visited[MAX_LEN] = { 0, };
int T, A, B;

void solved() {
	queue<pair<int, string>> queue;

	queue.push({ A, "" });

	while (!queue.empty()) {
		int n = queue.front().first;
		string str = queue.front().second;
		if (n == B) {
			cout << str << endl;
			return;
		}

		queue.pop();

		int D, S, L, R;

		// D = 2n mod 10000
		D = (2 * n) % MOD;
		if (!visited[D]) {
			visited[D] = VISITED;
			queue.push({ D, str + "D" });
		}

		// S = n - 1
		S = n - 1;
		if (S < 0) S = 9999;
		if (!visited[S]) {
			visited[S] = VISITED;
			queue.push({ S, str + "S" });
		}

		// L = (n * 10) % 10000 + n / 1000
		L = (n * 10) % 10000 + n / 1000;
		if (!visited[L]) {
			visited[L] = VISITED;
			queue.push({ L, str + "L" });
		}

		// R = (n / 10) + (n % 10) * 1000
		R = (n / 10) + (n % 10) * 1000;
		if (!visited[R]) {
			visited[R] = VISITED;
			queue.push({ R, str + "R" });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> A >> B;
		solved();
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}