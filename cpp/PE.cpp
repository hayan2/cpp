#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    vector<int> beta(M);
    for (int i = 0; i < M; i++) {
        cin >> beta[i];
    }
        
    vector<int> maxDiffs(N, 0);
    for (int j = 0; j < N; j++) {
        int maxDiff = 0;
        for (int i = 0; i < N; i++) {
            maxDiff = max(maxDiff, abs(A[i][j] - B[i][j]));
        }
        maxDiffs[j] = maxDiff;
    }

    int totalDiff = 0;
    for (int k = 0; k < M; k++) {
        totalDiff += maxDiffs[beta[k] - 1];
    }

    cout << totalDiff << '\n';
    return 0;
}
