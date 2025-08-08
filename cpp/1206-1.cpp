#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

const int IMOD = 1000;
const int DMOD = 1000.0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> ravg(N);
    for (int i = 0; i < N; i++) {
        double cache;
        cin >> cache;
        
        ravg[i] = static_cast<int>(cache * DMOD + 0.5);
    }
        
    for (int num = 1; num <= IMOD; num++) {
        vector<bool> pavg(10001, false);        
        for (int score = 0; score <= num * 10; score++) {
            int avg = (score * IMOD) / num;
            if (avg <= 10000) {
                pavg[avg] = true;
            }
        }
        //
        bool flag = true;
        for (int x : ravg) {
            if (!pavg[x]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << num;
            return 0;
        }
    }


	return 0;
}