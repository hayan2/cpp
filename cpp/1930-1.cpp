#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> mv(int c1, int c2, int c3, int c4) {
    return { c1, c2, c3, c4 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    while (K--) {
        vector<int> A(4);
        vector<int> B(4);

        for (int i = 0; i < 4; i++) cin >> A[i];
        for (int i = 0; i < 4; i++) cin >> B[i];

        set<vector<int>> cache;

        cache.insert(mv(A[0], A[1], A[2], A[3]));
        cache.insert(mv(A[0], A[2], A[3], A[1]));
        cache.insert(mv(A[0], A[3], A[1], A[2]));

        cache.insert(mv(A[1], A[0], A[3], A[2]));
        cache.insert(mv(A[1], A[3], A[2], A[0]));
        cache.insert(mv(A[1], A[2], A[0], A[3]));

        cache.insert(mv(A[2], A[0], A[1], A[3]));
        cache.insert(mv(A[2], A[1], A[3], A[0]));
        cache.insert(mv(A[2], A[3], A[0], A[1]));

        cache.insert(mv(A[3], A[0], A[2], A[1]));
        cache.insert(mv(A[3], A[2], A[1], A[0]));
        cache.insert(mv(A[3], A[1], A[0], A[2]));

        cout << (cache.count(B) ? "1\n" : "0\n");
    }

    return 0;
}