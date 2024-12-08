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
int isConnected[MAX_ILND][MAX_ILND];
int dist[MAX_ILND][MAX_ILND];
int dx[DIR_LEN] = { -1, 0, 1, 0 };
int dy[DIR_LEN] = { 0, -1, 0, 1 };
int N, M, islandNum = 0;

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

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

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
		if (x < 1 || x > M) return;

		distance++;
		x++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		isConnected[cx][cy] = CONNECTED;
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void backWidth(int x, int y) {
	int distance = 1, curNum = map[x][y];

	while (!map[x][y]) {
		if (x < 1 || x > M) return;

		distance++;
		x--;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		isConnected[cx][cy] = CONNECTED;
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void upHeight(int x, int y) {
	int distance = 0, curNum = map[x][y];
	y++;

	while (!map[x][y]) {
		if (y < 1 || y > N) return;

		distance++;
		y++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		isConnected[cx][cy] = CONNECTED;
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void downHeight(int x, int y) {
	int distance = 0, curNum = map[x][y];
	y--;

	while (!map[x][y]) {
		if (y < 1 || y > N) return;

		distance++;
		y--;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cx >= 0 && cy < MAX_ILND) {
		isConnected[cx][cy] = CONNECTED;
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
	cin >> N >> M;
	memset(visited, 0, sizeof(visited));
	memset(isConnected, 0, sizeof(isConnected));
	fill(&dist[0][0], &dist[MAX_ILND - 1][MAX_ILND], MAX_LEN);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (!visited[x][y] && map[x][y]) {
				putIslandNum(x, y);
			}
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (map[x][y]) {
				goWidth(x, y);
				backWidth(x, y);
				upHeight(x, y);
				downHeight(x, y);
			}
		}
	}	

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (dist[x][y] > 1 && dist[x][y] < MAX_LEN) {
				cache.push_back({ dist[x][y], { x, y } });
			}
		}
	}
	cout << "\n";
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cout << map[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cout << dist[x][y] << " ";
		}
		cout << "\n";
	}

	sort(cache.begin(), cache.end());
	for (Mst cur : cache) {
		int u = cur.second.first;
		int v = cur.second.second;
		int w = cur.first;

		printf("u : %d, v : %d, w : %d\n", u, v, w);
	}

	cout << solved();

	return 0;
}