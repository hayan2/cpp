#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX_NODES = 105; // 1(S) + 1(T) + 50(N) + 50(M) = 102

// ��Ʈ��ũ ���� ���� ���� ����
int N, M;
int capacity[MAX_NODES][MAX_NODES];
vector<int> adj[MAX_NODES];
int level[MAX_NODES];
int work[MAX_NODES];
int source, sink;

// Dinic �˰���: ���� �׷��� ���� (BFS)
bool bfs() {
    fill(level, level + MAX_NODES, -1);
    level[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (level[v] == -1 && capacity[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}

// Dinic �˰���: ���� ���� Ž�� (DFS)
int dfs(int u, int flow) {
    if (u == sink) return flow;
    for (int& i = work[u]; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (level[v] == level[u] + 1 && capacity[u][v] > 0) {
            int df = dfs(v, min(flow, capacity[u][v]));
            if (df > 0) {
                capacity[u][v] -= df;
                capacity[v][u] += df;
                return df;
            }
        }
    }
    return 0;
}

// �ִ� ������ ����ϴ� �Լ�
int max_flow() {
    int total_flow = 0;
    while (bfs()) {
        fill(work, work + MAX_NODES, 0);
        while (true) {
            int flow = dfs(source, INF);
            if (flow == 0) break;
            total_flow += flow;
        }
    }
    return total_flow;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> jimin_games(N);
    vector<int> hansu_games(M);
    int total_games = 0;

    for (int i = 0; i < N; ++i) {
        cin >> jimin_games[i];
        total_games += jimin_games[i];
    }
    int hansu_total_games = 0;
    for (int i = 0; i < M; ++i) {
        cin >> hansu_games[i];
        hansu_total_games += hansu_games[i];
    }

    // 1. �� ��� ���� �ٸ��� �Ұ���
    if (total_games != hansu_total_games) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> result(N, vector<int>(M, 0));

    // ��� ��ȣ ����: 0=source, 1~N=������, N+1~N+M=�Ѽ���, N+M+1=sink
    source = 0;
    sink = N + M + 1;

    // 2. (0,0)���� ������� ����ǥ ä���
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // 3. (i,j) ��⸦ 0���� �����ϰ�, �������� ����ǥ �ϼ��� �������� Ȯ��

            // ��Ʈ��ũ �ʱ�ȭ
            for (int k = 0; k < MAX_NODES; ++k) adj[k].clear();
            fill(&capacity[0][0], &capacity[MAX_NODES - 1][MAX_NODES], 0);

            int remaining_games = 0;
            // Source -> ������ ���� ����
            for (int p = 0; p < N; ++p) {
                if (jimin_games[p] > 0) {
                    adj[source].push_back(p + 1);
                    adj[p + 1].push_back(source);
                    capacity[source][p + 1] = jimin_games[p];
                }
                remaining_games += jimin_games[p];
            }
            // �Ѽ��� -> Sink ���� ����
            for (int p = 0; p < M; ++p) {
                if (hansu_games[p] > 0) {
                    adj[p + N + 1].push_back(sink);
                    adj[sink].push_back(p + N + 1);
                    capacity[p + N + 1][sink] = hansu_games[p];
                }
            }
            // ������ -> �Ѽ��� ���� ����
            for (int p = 0; p < N; ++p) {
                for (int q = 0; q < M; ++q) {
                    if (result[p][q] == 0) { // ���� �������� ���� ��⸸
                        adj[p + 1].push_back(q + N + 1);
                        adj[q + N + 1].push_back(p + 1);
                        // ���� �׽�Ʈ�ϴ� (i,j) ���� 0���� ���������Ƿ� �뷮 0
                        capacity[p + 1][q + N + 1] = (p == i && q == j) ? 0 : 1;
                    }
                }
            }

            if (max_flow() < remaining_games) {
                // (i,j)�� 0���� �θ� ����ǥ �ϼ��� �Ұ��� -> �ݵ�� 1�̾�� ��
                result[i][j] = 1;
                jimin_games[i]--;
                hansu_games[j]--;
            }
        }
    }

    // ���� ����ǥ ���
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << result[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}