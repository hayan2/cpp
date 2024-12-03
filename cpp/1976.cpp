#define MAX_LEN 201
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cache[MAX_LEN] = { 0, };
int N, M;

int find(int x) {
	if (cache[x] == x) return x;
	else return find(cache[x]);
}

void unionSet(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	cache[rootB] = rootA;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N + 1; i++) cache[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {			
			cin >> x;

			if (x) {
				unionSet(i, j);
			}
		}
	}

	int root;
	for (int i = 0; i < M; i++) {
		cin >> x;
		if (!i) {
			root = find(x);
			continue;
		}

		if (find(root) != find(x)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}