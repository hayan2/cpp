#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// �ؽ� �Լ� ����
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  // �� �ؽ� ���� XOR �������� ����
    }
};

int calculateSymmetry(const vector<pair<int, int>>& stars) {
    int maxSymmetry = 0;
    int n = stars.size();

    // �� �� �ֿ� ���� �߽����� ã�� ��Ī���� ���
    for (int i = 0; i < n; ++i) {
        unordered_map<pair<int, int>, int, pair_hash> centerCount;
        for (int j = i + 1; j < n; ++j) {
            // �� i�� �� j�� �߽��� ���
            int centerX = stars[i].first + stars[j].first;
            int centerY = stars[i].second + stars[j].second;

            pair<int, int> center = { centerX, centerY };
            centerCount[center]++;
        }

        // ���� ���� ���� ���� ū ��Ī�� ������Ʈ
        for (const auto& entry : centerCount) {
            maxSymmetry = max(maxSymmetry, entry.second);
        }
    }

    // �ִ� ��Ī���� ��� (��Ī ���̹Ƿ� * 2)
    return maxSymmetry * 2;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> stars(n);

    // �Է� ��ǥ ����
    for (int i = 0; i < n; ++i) {
        cin >> stars[i].first >> stars[i].second;
    }

    // �ִ� ��Ī�� ���
    cout << calculateSymmetry(stars) << endl;

    return 0;
}
