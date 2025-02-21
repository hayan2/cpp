#define MAX_LEN 91
#define ROOT 65
#define VISITED 1
#define LEFT 0
#define RIGHT 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int V;

void preorder(char s) {
	if (s == '.') {
		return;
	}	

	cout << s;
	preorder(tree[(int)s][LEFT]);
	preorder(tree[(int)s][RIGHT]);
}

void inorder(char s) {
	if (s == '.') {
		return;
	}

	inorder(tree[(int)s][LEFT]);
	cout << s;
	inorder(tree[(int)s][RIGHT]);
}

void postorder(char s) {
	if (s == '.') {
		return;
	}

	postorder(tree[(int)s][LEFT]);
	postorder(tree[(int)s][RIGHT]);
	cout << s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	char u, l, r;
	cin >> V;

	for (int i = 0; i < V; i++) {
		cin >> u >> l >> r;
		tree[(int)u].push_back(l);
		tree[(int)u].push_back(r);
	}

	preorder(ROOT);
	cout << '\n';
	inorder(ROOT);
	cout << '\n';
	postorder(ROOT);

	return 0;
}