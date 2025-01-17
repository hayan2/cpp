#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1e9
#define MAX_LEN 1001
#define COLOR_LEN 3
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int cache[MAX_LEN][3];
int dp[MAX_LEN][3];
int N;

int solve(int firstColor) {
    for (int i = 0; i < COLOR_LEN; i++) 
        dp[0][i] = (i == firstColor) ? dp[0][i] = cache[0][i] : dp[0][i] = INF;        
    
    for (int i = 1; i < N; i++) {
        dp[i][RED] = cache[i][RED] + min(dp[i - 1][GREEN], dp[i - 1][BLUE]);
        dp[i][GREEN] = cache[i][GREEN] + min(dp[i - 1][RED], dp[i - 1][BLUE]);
        dp[i][BLUE] = cache[i][BLUE] + min(dp[i - 1][RED], dp[i - 1][GREEN]);
    }

    int ret = INF;

    for (int i = 0; i < COLOR_LEN; i++) {
        if (i != firstColor) {
            ret = min(ret, dp[N - 1][i]);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cache[i][RED] >> cache[i][GREEN] >> cache[i][BLUE];
    }

    int res = INF;
    for (int firstColor = 0; firstColor < 3; firstColor++) {
        res = min(res, solve(firstColor));
    }

    cout << res;

    return 0;
}
