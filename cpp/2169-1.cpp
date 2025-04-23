#include <iostream>
#include <vector>

using namespace std;

int n, m;
int board[1001][1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    // 첫 번째 행 초기화
    dp[0][0] = board[0][0];

    for (int j = 1; j < m; ++j)
        dp[0][j] = dp[0][j - 1] + board[0][j];

    // 각 행별로 최대 탐사 가치 계산
    for (int i = 1; i < n; ++i)
    {
        // 왼쪽에서 오는 값 계산
        vector<int> left(m), right(m);

        left[0] = dp[i - 1][0] + board[i][0];

        for (int j = 1; j < m; ++j)
            left[j] = max(left[j - 1], dp[i - 1][j]) + board[i][j];

        // 오른쪽에서 오는 값 계산
        right[m - 1] = dp[i - 1][m - 1] + board[i][m - 1];

        for (int j = m - 2; j >= 0; --j)
            right[j] = max(right[j + 1], dp[i - 1][j]) + board[i][j];

        // 왼쪽과 오른쪽을 병합하여 dp 갱신
        for (int j = 0; j < m; ++j)
            dp[i][j] = max(left[j], right[j]);
    }

    // 결과 출력
    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}