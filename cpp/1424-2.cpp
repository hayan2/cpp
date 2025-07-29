#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 13;

int main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, C;
        
    cin >> N >> L >> C;
       
    vector<int> cache;
    int tmp = (C + 1) / (L + 1);
    for (int k = 1; k <= tmp; k++) {
        if (!(k % MOD)) {
            cache.push_back(k);
        }
    }
        
    vector<int> dist(N + 1, -1);
    queue<int> q;
        
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
                
        if (cur == N) break;
        
        for (int k : cache) {
            int nxt = cur + k;
                       
            if (nxt <= N && dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
        
    cout << dist[N];

    return 0;
}