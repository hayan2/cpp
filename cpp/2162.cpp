#define lli long long
#define MAX_LEN 3001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

// WA

typedef struct Coor {
	lli x, y;
	
	void read() { cin >> x >> y; }
}Coordinate;

vector<pair<Coor, Coor>> line;
int sccidx[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int root[MAX_LEN];
int V, group, cnt = 0;

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) {
		root[b] = a;
		sccidx[a] += sccidx[b];
		group -= sccidx[b];
	}
	else if (a < b) {
		root[a] = b;
		sccidx[b] += sccidx[a];
		group -= sccidx[a];
	}
}

lli ccw(Coor p1, Coor p2, Coor p3) {
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

// ret 0 : p1 is farther from the origin
// ret 1 : p2 is farther from the origin
lli compareDistance(Coor p1, Coor p2) {
	lli d1 = p1.x * p1.x + p1.y * p1.y;
	lli d2 = p2.x * p2.x + p2.y * p2.y;

	if (d1 > d2) return 0;
	else return 1;
}

lli getDistance(Coor p1) {
	return sqrt(p1.x * p1.x + p1.y * p1.y);
}

lli isBetween(Coor p1, Coor p2, Coor p3) {
	return ((p1.x <= p3.x && p3.x <= p2.x) && (p1.y <= p3.y && p3.y <= p2.y)) || ((p1.x >= p3.x && p3.x >= p2.x) && (p1.y >= p3.y && p3.y >= p2.y));
}

bool isOverlapped() {
	return true;
}

void solved(int s) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			Coor p1 = line[i].first;
			Coor p2 = line[i].second;
			Coor p3 = line[j].first;
			Coor p4 = line[j].second;

			lli abc = ccw(p1, p2, p3);
			lli abd = ccw(p1, p2, p4);
			lli cda = ccw(p3, p4, p1);
			lli cdb = ccw(p3, p4, p2);

			lli l1 = abc * abd;
			lli l2 = cda * cdb;

			if (i == j) continue;

			if (l1 < 0 && l2 < 0) {
				printf("%d, %d are overlapped\n", i, j);
				unionSet(i, j);
			}
			else if (!l1 && !l2) {
				// The four points lie on a straight line.
				// (p1 < p4 && p2 > p4) (p1 < p3 && p2 > p3)
				if (!compareDistance(p1, p3) && (isBetween(p1, p2, p3) || isBetween(p1, p2, p4))) {
					printf("%d, %d are overlapped\n", i, j);
					unionSet(i, j);
				}
				else if (compareDistance(p1, p3) && (isBetween(p3, p4, p2) || isBetween(p3, p4, p1))) {
					printf("%d, %d are overlapped\n", i, j);
					unionSet(i, j);
				}
				else {
					printf("%d, %d are not overlapped\n", i, j);

				}
			}
			else if (!l1 || !l2) {
				// The three points lie on a straight line.
				if (isBetween(p1, p2, p3) || isBetween(p1, p2, p4) || isBetween(p3, p4, p1) || isBetween(p3, p4, p2)) {
					printf("%d, %d are overlapped\n", i, j);
					unionSet(i, j);
				}
				else {
					printf("%d, %d are not overlapped\n", i, j);

				}
			}
			else {
				printf("%d, %d are not overlapped\n", i, j);

			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	group = V;

	for (int i = 0; i < V; i++) {
		sccidx[i] = 1;
		root[i] = i;
	}

	for (int i = 0; i < V; i++) {
		Coor p1, p2;
		
		p1.read(), p2.read();
		if (compareDistance(p1, p2)) line.push_back({ p1, p2 });
		else line.push_back({ p2, p1 });
	}
	
	solved(0);

	for (int i = 0; i < V; i++) cnt = (cnt > sccidx[i]) ? cnt : sccidx[i];

	cout << group << "\n" << cnt;

	return 0;
}