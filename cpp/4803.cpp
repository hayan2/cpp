#define MAX_E 124751
#define MAX_LEN 501
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

typedef struct Edge {
	int u, v;
}Edge;

Edge tree[MAX_LEN];
int visited[MAX_LEN] = { 0, };

string solved(int N, int M) {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
		
	while (1) {		
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		int u, v;

		for (int i = 1; i <= M; i++) {
			cin >> u >> v;
			tree[i] = { u, v };
		}

		solved(N, M);

		memset(tree, 0, sizeof(tree));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}