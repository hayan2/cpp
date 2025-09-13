#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int len, i;
bool greaterThan;

void solve() {
    cin >> s;
    len = s.size();

    string p(len, '9');
    if (s == p) {
        s = "1";
        for (i = 0; i < len; i++) {
            s += '0';
        }
        cout << s << endl;
        return;
    }
    //
    string a = s;
    for (i = 0; i < len / 2; i++) {
        a[len - 1 - i] = a[i];
    }

    if (a > s) {
        cout << a << endl;
        return;
    }

    for (i = (len - 1) / 2; i >= 0; i--) {
        if (a[i] != '9') {
            a[i]++;
            break;
        }
        a[i] = '0';
    }
        
    for (i = 0; i < len / 2; i++) {
        a[len - 1 - i] = a[i];
    }

    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}