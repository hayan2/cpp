#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll point[10001];

int CCW(pll A, pll B, pll C) {
    ll ccw = (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

int intersection(pll A, pll B, pll C, pll D) {
    int ccw1 = CCW(A, B, C);
    int ccw2 = CCW(A, B, D);
    int ccw3 = CCW(C, D, A);
    int ccw4 = CCW(C, D, B);

    if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        if (B < C || D < A) return 0;
        else return 1;
    }
    else if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        point[i] = { x,y };
    }
    point[N] = point[0];

    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        ll x, y; cin >> x >> y;
        pll X = { x,y }, Y = { x + 1000000007, y + 1 }; // 선분 XY가 X에서 뻗어나가는 반직선 역할
        bool chk = 0;
        for (int j = 0; j < N; j++) {
            cnt += intersection(X, Y, point[j], point[j + 1]);
            if (CCW(point[j], X, point[j + 1]) == 0) { //다각형의 경계 위에 있는지 검사
                if ((point[j] <= X && X <= point[j + 1]) || (point[j + 1] <= X && X <= point[j])) {
                    chk = 1;
                    break;
                }
            }
        }
        if (chk) cout << 1 << '\n';
        else if (cnt & 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}