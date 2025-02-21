#define MAX_LEN 11
#define MAX_ILND 7
#define DIR_LEN 4
#define VISITED 1
#define CONNECTED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, pair<int, int>> Mst;

vector<Mst> cache;
int map[MAX_LEN][MAX_LEN];
int root[MAX_ILND];
int visited[MAX_LEN][MAX_LEN];
int dist[MAX_ILND][MAX_ILND];
int dx[DIR_LEN] = { -1, 0, 1, 0 };
int dy[DIR_LEN] = { 0, -1, 0, 1 };
int V, E, islandNum = 0;

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

void putIslandNum(int x, int y) {
	queue<pair<int, int>> queue;
	queue.push({ x, y });
	map[x][y] += islandNum;
	visited[x][y] = VISITED;

	while (!queue.empty()) {
		int curX = queue.front().first;
		int curY = queue.front().second;
		queue.pop();

		for (int i = 0; i < DIR_LEN; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 1 || ny < 1 || nx > V || ny > E) continue;

			if (!visited[nx][ny] && map[nx][ny]) {
				map[nx][ny] += islandNum;
				visited[nx][ny] = VISITED;
				queue.push({ nx, ny });
			}
		}
	}

	islandNum++;
}

void goWidth(int x, int y) {
	int distance = 0, curNum = map[x][y];
	x++;

	while (!map[x][y]) {
		if (x < 1 || x > E) return;

		distance++;
		x++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void backWidth(int x, int y) {
	int distance = 1, curNum = map[x][y];

	while (!map[x][y]) {
		if (x < 1 || x > E) return;

		distance++;
		x--;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void upHeight(int x, int y) {
	int distance = 0, curNum = map[x][y];
	y++;

	while (!map[x][y]) {
		if (y < 1 || y > V) return;

		distance++;
		y++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void downHeight(int x, int y) {
	int distance = 0, curNum = map[x][y];
	y--;

	while (!map[x][y]) {
		if (y < 1 || y > V) return;

		distance++;
		y--;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

int solved() {
	int ret = 0, cnt = 0;

	for (Mst cur : cache) {
		int u = cur.second.first;
		int v = cur.second.second;
		int w = cur.first;

		if (find(u) == find(v)) continue;
		if (cnt == islandNum - 1) return ret;

		cnt++;
		ret += w;
		unionSet(u, v);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < MAX_ILND; i++) root[i] = i;
	cin >> V >> E;

	memset(visited, 0, sizeof(visited));

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			dist[x][y] = MAX_LEN;
		}
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= E; j++) {
			cin >> map[i][j];
		}
	}

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			if (!visited[x][y] && map[x][y]) {
				putIslandNum(x, y);
			}
		}
	}

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			if (map[x][y]) {
				goWidth(x, y);
				backWidth(x, y);
				upHeight(x, y);
				downHeight(x, y);
			}
		}
	}

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			if (dist[x][y] > 1 && dist[x][y] < MAX_LEN) {
				cache.push_back({ dist[x][y], { x, y } });
			}
		}
	}


	cout << solved();

	return 0;
}