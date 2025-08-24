#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 101;
const int MAX_M = 71;
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int cache[MAX_N][MAX_M] = { 0, };
bool visited[MAX_N][MAX_M] = { false, };
int N, M;

bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cache[i][j];
		}
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				bool flag = true;
				queue<pii> q;
				q.push({ i, j });
				visited[i][j] = true;

				vector<pii> cur;
				cur.push_back({ i, j });

				int h = cache[i][j];

				int head = 0;
				while (head < cur.size()) {
					int x = cur[head].first;
					int y = cur[head].second;
					head++;

					for (int k = 0; k < 8; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (isValid(nx, ny)) {
							if (cache[nx][ny] > h) flag = false;
							if (cache[nx][ny] == h && !visited[nx][ny]) {
								visited[nx][ny] = true;
								cur.push_back({ nx, ny });
							}
						}
					}
				}
				if (flag) res++;
			}
		}
	}
	//

	cout << res;

	return 0;
}