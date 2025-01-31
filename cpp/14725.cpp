#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>

#define MAX_LEN 15001

using namespace std;

string cache;
int N, K;

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

	cin >> N;
	Node* root = new Node;

	while (N--) {
		cin >> K;

		Node* cur = root;
		while (K--) {
			cin >> cache;

			if (cur->element.find(cache) == cur->element.end()) {
				cur->element[cache] = new Node;
			}
			cur = cur->element[cache];
		}
	}

	display(root, "");

	return 0;
}