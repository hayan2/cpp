#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// 문제의 최대 범위 N을 상수로 정의
const int MAX_N = 10000;

// 전역 변수: 프로그램의 여러 부분에서 접근해야 하므로 전역으로 선언
std::vector<bool> is_prime; // 소수 여부를 저장할 배열
std::vector<int> ans;       // 각 N에 대한 정답을 저장할 테이블

// 에라토스테네스의 체 함수
// n까지의 모든 소수 여부를 담은 bool 벡터를 생성합니다.
void sieve(int n) {
    // is_prime 벡터를 n+1 크기로 만들고 모두 true로 초기화
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    // 2부터 n의 제곱근까지만 확인하는 최적화
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) { // p가 소수라면
            // p의 배수들을 모두 소수가 아니라고 표시
            // p*p부터 시작하는 최적화
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
}

// 모든 계산을 미리 수행하는 전처리 함수
void precompute() {
    // 1단계: 에라토스테네스의 체를 실행하여 소수 정보 만들기
    sieve(MAX_N);

    // 3단계(준비): 정답 테이블을 -1로 초기화
    // ans[i]는 "i 이하의 최대 합성소수"를 의미합니다.
    ans.assign(MAX_N + 1, -1);

    // 2 & 3단계: 100부터 최대 범위까지 합성소수를 찾으면서 동시에 정답 테이블 만들기
    for (int i = 1; i <= MAX_N; ++i) {
        // 일단 이전까지의 정답을 그대로 가져옵니다 (누적 최댓값)
        if (i > 0) {
            ans[i] = ans[i - 1];
        }

        // '합성소수'는 세 자리 이상이므로 100 미만은 검사할 필요 없음
        if (i < 100) {
            continue;
        }

        // [조건 1] i가 합성수인가? (소수이면 건너뜀)
        if (is_prime[i]) {
            continue;
        }

        // [조건 2] i의 모든 연속되는 진부분수가 소수인가?
        std::string s = std::to_string(i);
        bool all_substrings_are_prime = true;

        // 부분 문자열의 길이가 2부터 (원래 문자열 길이 - 1)까지 반복
        for (int len = 2; len < s.length(); ++len) {
            for (int start = 0; start <= s.length() - len; ++start) {
                // stoi: 문자열을 정수로 변환 ("07" -> 7)
                int sub_num = std::stoi(s.substr(start, len));

                // is_prime 배열로 즉시 소수 여부 확인
                if (!is_prime[sub_num]) {
                    all_substrings_are_prime = false;
                    break;
                }
            }
            if (!all_substrings_are_prime) {
                break;
            }
        }

        // 모든 조건을 만족했다면, i는 새로운 '최대 합성소수'입니다.
        if (all_substrings_are_prime) {
            ans[i] = i; // 정답 테이블의 현재 위치 값을 i로 갱신
        }
    }
}

int main() {
    // C++ 입출력 속도 향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // [전처리] 프로그램 시작 시 단 한 번만 모든 계산을 수행
    precompute();

    int T; // 테스트케이스의 수
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;

        // [쿼리 응답] 미리 계산된 정답 테이블에서 값을 꺼내 바로 출력
        std::cout << ans[N] << "\n";
    }

    return 0;
}