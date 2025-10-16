#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int ROW = 8;
const int COL = 7;

char cache[ROW][COL];
bool visited[ROW][COL];
bool used[7][7];
int res = 0;

void solve(int r, int c) {
    while (r < ROW && visited[r][c]) {
        c++;
        if (c == COL) {
            r++;
            c = 0;
        }
    }
        
    if (r == ROW) {
        res++;
        return;
    }
        
    if (c + 1 < COL && !visited[r][c + 1]) {
        int d1 = cache[r][c] - '0';
        int d2 = cache[r][c + 1] - '0';
    
        if (!used[min(d1, d2)][max(d1, d2)]) { 
            used[min(d1, d2)][max(d1, d2)] = true;
            visited[r][c] = true;
            visited[r][c + 1] = true;

            solve(r, c);

            used[min(d1, d2)][max(d1, d2)] = false;
            visited[r][c] = false;
            visited[r][c + 1] = false;
        }
    }

    if (r + 1 < ROW && !visited[r + 1][c]) {
        int d1 = cache[r][c] - '0';
        int d2 = cache[r + 1][c] - '0';

        if (!used[min(d1, d2)][max(d1, d2)]) {
            used[min(d1, d2)][max(d1, d2)] = true;
            visited[r][c] = true;
            visited[r + 1][c] = true;

            solve(r, c);

            used[min(d1, d2)][max(d1, d2)] = false;
            visited[r][c] = false;
            visited[r + 1][c] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, false, sizeof visited);
    memset(used, false, sizeof used);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cin >> cache[i][j];
        }
    }

    solve(0, 0);

    cout << res;

    return 0;
}