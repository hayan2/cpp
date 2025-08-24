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

                // BFS�� ���� ������ ����� ���� Ž�� �� �ֺ� Ȯ��
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

                // ���� ���� �׷� �ֺ��� �� ���� ���츮�� �ִ��� ���� Ȯ��
                // ���� BFS �������� �̹� ��� �ֺ��� Ȯ�������Ƿ�,
                // ��� �� �κ��� �ʿ� ������ ������ ��Ȯ���� ���� �߰��� �� �ֽ��ϴ�.
                // �׷���, BFS�� ���鼭 is_peak �÷��׸� �����ϴ� ���� �� ȿ�����Դϴ�.
                // ���� �� �ڵ�ó�� BFS ������ is_peak�� �Ǵ��ϴ� ���� �����ϴ�.
                if (is_peak) {
                    peak_count++;
                }
            }
        }
    }

    cout << peak_count << endl;

    return 0;
}