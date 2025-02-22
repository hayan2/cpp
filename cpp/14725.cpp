#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>

#define MAX_LEN 15001

using namespace std;

string sccidx;
int V, K;

typedef struct Node {
	map<string, Node*> element;
}Node;

void display(Node* root, string depth) {
	for (auto cur : root->element) {
		cout << depth + cur.first << "\n";
		display(cur.second, depth + "--");
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	Node* root = new Node;

	while (V--) {
		cin >> K;

		Node* cur = root;
		while (K--) {
			cin >> sccidx;

			if (cur->element.find(sccidx) == cur->element.end()) {
				cur->element[sccidx] = new Node;
			}
			cur = cur->element[sccidx];
		}
	}

	display(root, "");

	return 0;
}