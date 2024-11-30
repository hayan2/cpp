#define MAX_LEN 1000001
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cache[MAX_LEN];
int N, M;

// get root node
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

	cin >> N >> M;

	for (int i = 1; i <= N; i++) cache[i] = i;
	int x, a, b;

	while (M--) {
		cin >> x >> a >> b;

		switch (x) {
		case 0:
			unionSet(a, b);
			break;
		case 1:
			int rootA = find(a);			
			int rootB = find(b);			
			if (rootA == rootB) cout << "YES\n";
			else cout << "NO\n";
			break;
		}
	}

	return 0;
}