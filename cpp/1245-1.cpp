#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int peak_count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                bool is_peak = true;
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;

                vector<pair<int, int>> current_group;
                current_group.push_back({ i, j });

                int current_height = grid[i][j];

                // BFS로 같은 높이의 연결된 격자 탐색 및 주변 확인
                int head = 0;
                while (head < current_group.size()) {
                    int x = current_group[head].first;
                    int y = current_group[head].second;
                    head++;

                    for (int k = 0; k < 8; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (is_valid(nx, ny)) {
                            if (grid[nx][ny] > current_height) {
                                is_peak = false;
                            }
                            if (grid[nx][ny] == current_height && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                current_group.push_back({ nx, ny });
                            }
                        }
                    }
                }

                // 같은 높이 그룹 주변에 더 높은 봉우리가 있는지 최종 확인
                // 위의 BFS 루프에서 이미 모든 주변을 확인했으므로,
                // 사실 이 부분은 필요 없지만 로직의 명확성을 위해 추가할 수 있습니다.
                // 그러나, BFS를 돌면서 is_peak 플래그를 관리하는 것이 더 효율적입니다.
                // 따라서 위 코드처럼 BFS 내에서 is_peak를 판단하는 것이 좋습니다.
                if (is_peak) {
                    peak_count++;
                }
            }
        }
    }

    cout << peak_count << endl;

    return 0;
}