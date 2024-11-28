#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> preorder;

void postorder(int low, int high) {
	if (low >= high) return;	

	int root = preorder[low];
	int mid = low + 1;
	while (mid < high) {
		if (root < preorder[mid]) break;		
		mid++;
	}

	postorder(low + 1, mid);
	postorder(mid, high);
	cout << root << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node;

	while (cin >> node) {
		preorder.push_back(node);
	}

	postorder(0, preorder.size());

	return 0;
}