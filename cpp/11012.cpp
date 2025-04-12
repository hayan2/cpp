#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAX_N = 100003;

vector<int> xpos[MAX_N];
int T, N, M, x, y, l, r, b, t;

struct Node {
	ll val;
	Node* left;
	Node* right;

	Node(Node* left = NULL, Node* right = NULL) :
		left(left), right(right), val(0) {}

	Node* update(int low, int high, int x, ll val) {
		if (low <= x && x <= high) {
			if (low == high) {
				Node* leaf = new Node();
				leaf->val = this->val + val;

				return leaf;
			}

			int mid = (low + high) >> 1;

			Node* l = this->left->update(low, mid, x, val);
			Node* r = this->right->update(mid + 1, high, x, val);
			Node* leaf = new Node(l, r);
			leaf->val = l->val + r->val;

			return leaf;
		}

		return this;
	}
};

ll query(Node* node, int low, int high, int l, int r) {
	if (high < l || r < low) return 0LL;
	if (l <= low && high <= r) return node->val;
	
	ll ret = 0;

	int mid = (low + high) >> 1;
	
	ret += query(node->left, low, mid, l, r);
	ret += query(node->right, mid + 1, high, l, r);

	return ret;	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < MAX_N; i++) xpos[i].clear();
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			x++, y++;

			xpos[y].push_back(x);
		}

		vector<Node*> segmentTree(MAX_N);
		segmentTree[0] = new Node();
		segmentTree[0]->left = segmentTree[0]->right = segmentTree[0];
		segmentTree[0]->val = 0;

		for (int i = 1; i < MAX_N; i++) {
			segmentTree[i] = segmentTree[i - 1];
			for (auto& x : xpos[i]) {
				segmentTree[i] = segmentTree[i]->update(1, MAX_N, x, 1);
			}
		}

		ll res = 0;
		while (M--) {
			cin >> l >> r >> b >> t;
			l++, r++, b++, t++;

			res += query(segmentTree[t], 1, MAX_N, l, r);
			res -= query(segmentTree[b - 1], 1, MAX_N, l, r);
		}

		cout << res << "\n";
	}

	return 0;
}