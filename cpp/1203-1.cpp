#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int N, K;
double P[51];
double dp[51][51][51][2];

double getPRight(int i) {
    if (i == N) return 0;
    return P[i];
}

double getPLeft(int i) {
    if (i == N) return 0;
    return 1.0 - P[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i < N; ++i) cin >> P[i];

    if (N == 1) {
        cout << (K == 1 ? 1.0 : 0.0) << endl;
        return 0;
    }

    if (K == N) {
        cout << 0.0 << endl;
        return 0;
    }

    dp[1][K][K][0] = 1.0;


    for (int len = 1; len < N - 1; ++len) {
        for (int l = 1; l < N; ++l) {            
            for (int r = l; r < N; ++r) {                
                if (r - l + 1 != len) continue;
                                
                double pl = dp[len][l][r][0];
                if (pl > 0) {                    
                    int nl = l - 1;
                    if (nl >= 1) dp[len + 1][nl][r][0] += pl * getPLeft(l);                    
                    dp[len][l][r][1] += pl * getPRight(l);
                }
                                
                double pr = dp[len][l][r][1];
                if (pr > 0) {
                
                    int nr = r + 1;
                    if (nr < N) dp[len + 1][l][nr][1] += pr * getPRight(r);                    
                    dp[len][l][r][0] += pr * getPLeft(r);
                }
            }
        }
    }

    double prob1 = dp[N - 1][1][N - 1][0];
    double probm1 = dp[N - 1][1][N - 1][1];

    double res = (prob1 * getPLeft(1)) + (probm1 * getPRight(N - 1));

    cout << fixed << setprecision(10) << res;

    return 0;
}