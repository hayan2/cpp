#define MAX_LEN 1001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

// 4% WA

typedef struct Coordinate {
	double x, y;
} Coordinate;

typedef pair<double, pair<int, int>> Type;

vector<Coordinate> pos;
vector<Type> dist;
int root[MAX_LEN];
double res = 0;
int N, M;

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) root[b] = a;
	else root[a] = b;
}

double getDistance(Coordinate P, Coordinate Q) {
	return sqrt(pow(Q.x - P.x, 2) + pow(Q.y - P.y, 2));
}

double solved() {
	double ret = 0.0;
	int cnt = 0;

	for (Type cur : dist) {
		int u = cur.second.first;
		int v = cur.second.second;
		double w = cur.first;

		if (find(u) == find(v)) continue;

		cnt++;
		if (cnt == N - 1) break;
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

	cin >> N >> M;
	for (int i = 0; i < N + 1; i++) root[i] = i;
	double x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		pos.push_back({ x, y });
	}

	int p, q;
	for (int i = 0; i < M; i++) {
		cin >> p >> q;
		unionSet(p - 1, q - 1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			dist.push_back({ getDistance(pos[i], pos[j]), { i, j } });
		}
	}
	sort(dist.begin(), dist.end());
	res += solved();

	cout << round(res * 100) / 100;

	return 0;
}