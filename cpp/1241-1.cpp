#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1000001;

int cnt[MAX_N] = { 0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> students(N);
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> students[i];
        cnt[students[i]]++;
        max_val = max(max_val, students[i]);
    }

    vector<int> hits(N);
    // 각 학생에 대해 직접 약수를 찾아 계산
    for (int i = 0; i < N; i++) {
        int current_num = students[i];
        int total_hits = 0;
        for (int j = 1; j * j <= current_num; j++) {
            if (current_num % j == 0) {
                // j가 약수
                total_hits += cnt[j];
                // current_num / j 가 j와 다른 약수일 경우
                if (j * j != current_num) {
                    total_hits += cnt[current_num / j];
                }
            }
        }
        // 자기 자신을 친 횟수 1을 빼준다.
        hits[i] = total_hits - 1;
    }

    for (int hit_count : hits) {
        cout << hit_count << "\n";
    }

    return 0;
}