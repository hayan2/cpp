#define MAX_LEN 1001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

// 4% WA

typedef struct Coor {
	double x, y;
} Coordinate;

typedef pair<double, pair<int, int>> Type;

vector<Coor> pos;
vector<Type> dist;
vector<Type> tmp;
int visited[MAX_LEN][MAX_LEN];
int root[MAX_LEN];
double res = 0;
int V, E;

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

double getDistance(Coor P, Coor Q) {
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
		if (cnt == V) break;
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

	cin >> V >> E;
	for (int i = 0; i < V + 1; i++) root[i] = i;
	double x, y;
	for (int i = 0; i < V; i++) {
		cin >> x >> y;

		pos.push_back({ x, y });
	}

	int p, q;
	for (int i = 0; i < E; i++) {
		cin >> p >> q;
		visited[p - 1][q - 1] = visited[q - 1][p - 1] = VISITED;
		double retDistance = getDistance(pos[p - 1], pos[q - 1]);
		dist.push_back({ retDistance, { p - 1, q - 1 } });
		res -= retDistance;
	}

	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (!visited[i][j] && !visited[j][i]) {
				tmp.push_back({ getDistance(pos[i], pos[j]), { i, j } });
			}
		}
	}
	sort(tmp.begin(), tmp.end());
	dist.insert(dist.end(), tmp.begin(), tmp.end());
	res += solved();

	cout << round(res * 100) / 100;

	return 0;
}