#define MAX_LEN 3001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

typedef struct Coor {
	int x, y;

	void read() { cin >> x >> y; }
};

vector<pair<Coor, Coor>> line;
int N;
int root[MAX_LEN];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	root[a] += root[b];
	root[b] = a;
}

int ccw(Coor p1, Coor p2, Coor p3) {
	int tmp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	tmp = tmp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

bool compare(Coor p1, Coor p2) {
	if (p1.x > p2.x) return 1;	
	else if (p1.x < p2.x) return 0;	
	else {
		if (p1.y > p2.y) return 1;		
		else return 0;
	}
}

bool isOverlapped(Coor p1, Coor p2, Coor p3, Coor p4) {
	int abc = ccw(p1, p2, p3);
	int abd = ccw(p1, p2, p4);
	int cda = ccw(p3, p4, p1);
	int cdb = ccw(p3, p4, p2);

	bool l1 = (abc * abd <= 0);
	bool l2 = (cda * cdb <= 0);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (compare(p1, p2)) swap(p1, p2);		
		if (compare(p3, p4)) swap(p3, p4);
		if (compare(p3, p2) || compare(p1, p4)) l1 = false;
	}

	return (l1 && l2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		Coor p1, p2;

		p1.read(), p2.read();

		line.push_back({ p1, p2 });
	}

	memset(root, -1, sizeof(root));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (isOverlapped(line[i].first, line[i].second, line[j].first, line[j].second)) {
				unionSet(i, j);
			}
		}
	}

	int group = 0, cnt = 1;

	for (int i = 0; i < N; i++) {
		if (root[i] < 0) group++;
		cnt = min(cnt, root[i]);
	}

	cout << group << '\n' << -cnt;

	return 0;
}