#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> A, B;

void flip(int r, int c) {
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    A.assign(N, vector<int>(M));
    B.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            A[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            B[i][j] = row[j] - '0';
        }
    }

    if (N < 3 || M < 3) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] != B[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) cout << 0 << endl;        
        else cout << -1 << endl;    
        return 0;
    }

    int cnt = 0;
    
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {            
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                cnt++;
            }
        }
    }
       
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}