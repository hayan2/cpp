#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double dp[55][55][55];
bool visited[55][55][55];
int N, K;
double P[55];

int mod(int x) {
    if (x == 0) return N;
    if (x > N) return x - N;
    if (x < 1) return x + N;
    return x;
}

double solve(int l, int r, int cur) {
    if (visited[l][r][cur]) return dp[l][r][cur];
    visited[l][r][cur] = true;
    double& ret = dp[l][r][cur];
    if ((l == 1 && r == N) || (r == l - 1 + N)) { // 모두 방문함
        return ret = (cur == N ? 1.0 : 0.0);
    }

    int left = mod(cur - 1);
    int right = mod(cur + 1);

    double pr = P[cur];
    double pl = 1 - P[cur];

    // 오른쪽으로 줄 때
    if ((l <= r && right <= r && right >= l) || (l > r && (right >= l || right <= r)))
        ret += pr * solve(l, r, right);
    else
        ret += pr * solve(l, mod(r + 1), right);

    // 왼쪽으로 줄 때
    if ((l <= r && left <= r && left >= l) || (l > r && (left >= l || left <= r)))
        ret += pl * solve(l, r, left);
    else
        ret += pl * solve(mod(l - 1), r, left);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i < N; i++) cin >> P[i];
    P[N] = 0.5; // 더미 (사용되지 않음)
    cout << fixed << setprecision(10) << solve(K, K, K) << "\n";
}
