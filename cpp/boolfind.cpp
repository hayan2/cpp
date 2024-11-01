#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void sol(int n) {
    int low = 0;
    int high = n - 1;

    while (low < high - 1) {
        int mid = low + (high - low) / 2;

        cout << "READ " << mid << endl;
        string resp;
        cin >> resp;

        if (resp == "true") {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << "OUTPUT " << low << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
                
        sol(n);
    }

    return 0;
}
