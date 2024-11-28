#define MAX_LEN 100001
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
int pos[MAX_LEN];
int N;

void preorder(int inLow, int inHigh, int postLow, int postHigh) {
	if (inLow > inHigh || postLow > postHigh) {
		return;
	}

	int root = postorder[postHigh];
	int rootIndex = pos[root];
	int leftSize = rootIndex - inLow;
	int rightSize = inHigh - rootIndex;

	cout << root << " ";

	preorder(inLow, rootIndex - 1, postLow, postLow + leftSize - 1);
	preorder(rootIndex + 1, inHigh, postLow + leftSize, postHigh - 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int node;
	for (int i = 0; i < N; i++) {
		cin >> node;
		inorder.push_back(node);
		pos[node] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> node;
		postorder.push_back(node);
	}

	preorder(0, N - 1, 0, N - 1);

	return 0;
}