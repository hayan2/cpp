#define MAX_LEN 100001
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> indegree;
vector<int> postorder;
int pos[MAX_LEN];
int V;

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

	cin >> V;

	int node;
	for (int i = 0; i < V; i++) {
		cin >> node;
		indegree.push_back(node);
		pos[node] = i;
	}
	for (int i = 0; i < V; i++) {
		cin >> node;
		postorder.push_back(node);
	}

	preorder(0, V - 1, 0, V - 1);

	return 0;
}