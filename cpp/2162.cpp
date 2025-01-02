#define MAX_LEN 3001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef struct Coordinate {
	int x, y;
	
	void read() { cin >> x >> y; }
}Coordinate;

vector<pair<Coordinate, Coordinate>> line;
int cache[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int root[MAX_LEN];
int N, group, cnt = 0;

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		root[b] = a;
		cache[b] += cache[a];
	}
	else if (a > b) {
		root[a] = b;
		cache[a] += cache[b];
	}
}

int ccw(Coordinate p1, Coordinate p2, Coordinate p3) {
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

bool isOverlapped() {

}

void solved(int s) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			Coordinate p1 = line[i].first;
			Coordinate p2 = line[i].second;
			Coordinate p3 = line[j].first;
			Coordinate p4 = line[j].second;

			int l1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
			int l2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);


		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	group = N;	
	for (int i = 0; i < MAX_LEN; i++) {
		cache[i] = 1;
		root[i] = i;
	}

	for (int i = 0; i < N; i++) {
		Coordinate p1, p2;
		
		p1.read(), p2.read();
		line.push_back({ p1, p2 });
	}

	solved(0);

	return 0;
}