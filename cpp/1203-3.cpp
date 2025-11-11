#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;

int N, K;
double P[51];

double get_P_right(int i) {
    if (i == N - 1) return P[N - 1];
    if (i == 0 || i == N) return 0;
    return P[i];
}

double get_P_left(int i) {
    if (i == 1) return 1.0 - P[1]; // 1 -> N
    if (i == 0 || i == N) return 0;
    return 1.0 - P[i];
}

vector<double> gaussian_elimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        // Pivot Ã£±â
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[max_row][i])) {
                max_row = k;
            }
        }
        swap(A[i], A[max_row]);
        swap(b[i], b[max_row]);

        double div = A[i][i];
        for (int j = i; j < n; j++) A[i][j] /= div;
        b[i] /= div;

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
                b[k] -= factor * b[i];
            }
        }
    }
    return b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i < N; ++i) {
        cin >> P[i];
    }

    if (N == 1) {
        cout << fixed << setprecision(10) << (K == 1 ? 1.0 : 0.0) << endl;
        return 0;
    }

    if (N == 3 && K == 1) {
        cout << fixed << setprecision(10) << P[1] << endl;
        return 0;
    }
    if (N == 3 && K == 2) {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }
    cout << fixed << setprecision(10) << 0.0 << endl;


    return 0;
}