#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int T, S;
};

bool cmp(const Job& a, const Job& b) {
    return a.S > b.S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Job> cache(N);
    for (int i = 0; i < N; ++i) {
        cin >> cache[i].T >> cache[i].S;
    }
        
    sort(cache.begin(), cache.end(), cmp);
    
    int lt = cache[0].S;
    
    for (int i = 0; i < N; ++i) {    
        if (lt > cache[i].S) lt = cache[i].S;
        lt -= cache[i].T;
    }
    
    cout << ((lt >= 0) ? lt : -1);
    //
    return 0;
}