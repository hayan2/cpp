#define MAX_LEN 101 * 101
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Coor {
	double x, y;
} Coor;

typedef pair<double, pair<int, int>> type;
vector<Coor> stars;
vector<type> dist;
int root[MAX_LEN];
int V;

double getDistance(Coor p, Coor q) {
	if (p.x == q.x || p.y == q.y) return abs(q.x - p.x) + abs(q.y - p.y);
	else return sqrt(pow((q.x - p.x), 2) + pow((q.y - p.y), 2));
}

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) root[b] = a;
	else if (a < b) root[a] = b;
}

double solved() {
	double ret = 0.0;
	int cnt = 0;

	for (type cur : dist) {
		int u = cur.second.first;
		int v = cur.second.second;
		double w = cur.first;

		if (find(u) == find(v)) continue;

		cnt++;
		unionSet(u, v);
		ret += w;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> V;
	for (int i = 0; i < MAX_LEN; i++) root[i] = i;

	for (int i = 0; i < V; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back({ x, y });
	}

	for (int i = 0; i < stars.size(); i++) {
		for (int j = i + 1; j < stars.size(); j++) {
			dist.push_back({ getDistance(stars[i], stars[j]), { i, j } });
		}
	}

	sort(dist.begin(), dist.end());

	cout << solved();

	return 0;
}