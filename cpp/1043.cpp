#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_SIZE = 52;

vector<int> str[MAX_SIZE];
int root[MAX_SIZE], t[MAX_SIZE] = { 0, };
int N, M, K, x, p, cache = 0;

int find(int x) {
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);
	if (t[root[a]] || t[root[b]]) t[root[a]] = t[root[b]] = 1;
	if (a < b) root[b] = a;
	else if (a > b) root[a] = b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < MAX_SIZE; i++) root[i] = i;
	cin >> N >> M;
	cin >> K;
	while (K--) {
		cin >> x;
		t[x] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> x;
			str[i].push_back(x);
		}
		for (int j = 1; j < p; j++)
			unionSet(str[i][j], str[i][j - 1]);
	}
	for (int i = 0; i < M; i++) {
		for (int cur = 0; cur < str[i].size(); cur++) {
			if (t[root[find(str[i][cur])]] == 1) break;
			if (cur == str[i].size() - 1) cache++;
		}
	}

	cout << cache;

	return 0;
}