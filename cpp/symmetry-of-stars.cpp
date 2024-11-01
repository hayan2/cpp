#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 해시 함수 정의
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  // 두 해시 값을 XOR 연산으로 결합
    }
};

int calculateSymmetry(const vector<pair<int, int>>& stars) {
    int maxSymmetry = 0;
    int n = stars.size();

    // 각 별 쌍에 대해 중심점을 찾고 대칭성을 계산
    for (int i = 0; i < n; ++i) {
        unordered_map<pair<int, int>, int, pair_hash> centerCount;
        for (int j = i + 1; j < n; ++j) {
            // 별 i와 별 j의 중심점 계산
            int centerX = stars[i].first + stars[j].first;
            int centerY = stars[i].second + stars[j].second;

            pair<int, int> center = { centerX, centerY };
            centerCount[center]++;
        }

        // 현재 별에 대해 가장 큰 대칭성 업데이트
        for (const auto& entry : centerCount) {
            maxSymmetry = max(maxSymmetry, entry.second);
        }
    }

    // 최대 대칭성을 출력 (대칭 쌍이므로 * 2)
    return maxSymmetry * 2;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> stars(n);

    // 입력 좌표 저장
    for (int i = 0; i < n; ++i) {
        cin >> stars[i].first >> stars[i].second;
    }

    // 최대 대칭성 출력
    cout << calculateSymmetry(stars) << endl;

    return 0;
}
