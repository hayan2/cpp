#define MAX_LEN 201
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sccidx[MAX_LEN] = { 0, };
int V, E;

int find(int x) {
	if (sccidx[x] == x) return x;
	else return find(sccidx[x]);
}

void unionSet(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	sccidx[rootB] = rootA;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int x;
	cin >> V >> E;
	for (int i = 1; i <= V + 1; i++) sccidx[i] = i;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {			
			cin >> x;

			if (x) {
				unionSet(i, j);
			}
		}
	}

	int root;
	for (int i = 0; i < E; i++) {
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