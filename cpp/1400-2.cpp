#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

const int INF = 1e9 + 7;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

struct Light {
    char state;
    int ew;
    int ns;
};

bool isGreen(int time, const Light& light, int dir) {
    int cycle = light.ew + light.ns;
    int tic = time % cycle;

    if (light.state == '-') return (tic < light.ew) ? dir == 1 : dir == 0;    
    else return (tic < light.ns) ? dir == 0 : dir == 1;
}


void solve() {
    int m, n;
    while (cin >> m >> n && (m != 0 || n != 0)) {
        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        pair<int, int> startPos, endPos;
        map<int, pair<int, int>> crossroads;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'A') startPos = { i, j };
                if (grid[i][j] == 'B') endPos = { i, j };
                if (isdigit(grid[i][j])) {
                    crossroads[grid[i][j] - '0'] = { i, j };
                }
            }
        }

        vector<Light> lights(crossroads.size());
        for (int i = 0; i < crossroads.size(); ++i) {
            int id;
            char init;
            int a, b;
            cin >> id >> init >> a >> b;
            lights[id] = { init, a, b };
        }

        vector<vector<int>> dist(m, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[startPos.first][startPos.second] = 0;
        pq.push({ 0, startPos.first, startPos.second });

        int result = -1;

        while (!pq.empty()) {
            tuple<int, int, int> cur = pq.top();
            pq.pop();

            int time = get<0>(cur);
            int r = get<1>(cur);
            int c = get<2>(cur);

            if (time > dist[r][c]) {
                continue;
            }
            if (r == endPos.first && c == endPos.second) {
                result = time;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == '.') {
                    continue;
                }

                int wt = 0;
                int current_time = time;

                if (isdigit(grid[nr][nc])) {
                    int id = grid[nr][nc] - '0';
                    int dir = (abs(r - nr) == 1) ? 0 : 1;

                    while (!isGreen(current_time, lights[id], dir)) {
                        wt++;
                        current_time++;
                    }
                }

                int nxt = time + wt + 1;

                if (nxt < dist[nr][nc]) {
                    dist[nr][nc] = nxt;
                    pq.push({ nxt, nr, nc });
                }
            }
        }

        if (result == -1) {
            cout << "impossible" << endl;
        }
        else {
            cout << result << endl;
        } //
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}