#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// ������ �ִ� ���� N�� ����� ����
const int MAX_N = 10000;

// ���� ����: ���α׷��� ���� �κп��� �����ؾ� �ϹǷ� �������� ����
std::vector<bool> is_prime; // �Ҽ� ���θ� ������ �迭
std::vector<int> ans;       // �� N�� ���� ������ ������ ���̺�

// �����佺�׳׽��� ü �Լ�
// n������ ��� �Ҽ� ���θ� ���� bool ���͸� �����մϴ�.
void sieve(int n) {
    // is_prime ���͸� n+1 ũ��� ����� ��� true�� �ʱ�ȭ
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0�� 1�� �Ҽ��� �ƴ�

    // 2���� n�� �����ٱ����� Ȯ���ϴ� ����ȭ
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) { // p�� �Ҽ����
            // p�� ������� ��� �Ҽ��� �ƴ϶�� ǥ��
            // p*p���� �����ϴ� ����ȭ
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
}

// ��� ����� �̸� �����ϴ� ��ó�� �Լ�
void precompute() {
    // 1�ܰ�: �����佺�׳׽��� ü�� �����Ͽ� �Ҽ� ���� �����
    sieve(MAX_N);

    // 3�ܰ�(�غ�): ���� ���̺��� -1�� �ʱ�ȭ
    // ans[i]�� "i ������ �ִ� �ռ��Ҽ�"�� �ǹ��մϴ�.
    ans.assign(MAX_N + 1, -1);

    // 2 & 3�ܰ�: 100���� �ִ� �������� �ռ��Ҽ��� ã���鼭 ���ÿ� ���� ���̺� �����
    for (int i = 1; i <= MAX_N; ++i) {
        // �ϴ� ���������� ������ �״�� �����ɴϴ� (���� �ִ�)
        if (i > 0) {
            ans[i] = ans[i - 1];
        }

        // '�ռ��Ҽ�'�� �� �ڸ� �̻��̹Ƿ� 100 �̸��� �˻��� �ʿ� ����
        if (i < 100) {
            continue;
        }

        // [���� 1] i�� �ռ����ΰ�? (�Ҽ��̸� �ǳʶ�)
        if (is_prime[i]) {
            continue;
        }

        // [���� 2] i�� ��� ���ӵǴ� ���κм��� �Ҽ��ΰ�?
        std::string s = std::to_string(i);
        bool all_substrings_are_prime = true;

        // �κ� ���ڿ��� ���̰� 2���� (���� ���ڿ� ���� - 1)���� �ݺ�
        for (int len = 2; len < s.length(); ++len) {
            for (int start = 0; start <= s.length() - len; ++start) {
                // stoi: ���ڿ��� ������ ��ȯ ("07" -> 7)
                int sub_num = std::stoi(s.substr(start, len));

                // is_prime �迭�� ��� �Ҽ� ���� Ȯ��
                if (!is_prime[sub_num]) {
                    all_substrings_are_prime = false;
                    break;
                }
            }
            if (!all_substrings_are_prime) {
                break;
            }
        }

        // ��� ������ �����ߴٸ�, i�� ���ο� '�ִ� �ռ��Ҽ�'�Դϴ�.
        if (all_substrings_are_prime) {
            ans[i] = i; // ���� ���̺��� ���� ��ġ ���� i�� ����
        }
    }
}

int main() {
    // C++ ����� �ӵ� ����� ���� ����
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // [��ó��] ���α׷� ���� �� �� �� ���� ��� ����� ����
    precompute();

    int T; // �׽�Ʈ���̽��� ��
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;

        // [���� ����] �̸� ���� ���� ���̺��� ���� ���� �ٷ� ���
        std::cout << ans[N] << "\n";
    }

    return 0;
}