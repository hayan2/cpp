#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add_one(string s) {
    int n = s.length();
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {
        int digit = (s[i] - '0') + carry;
        s[i] = (digit % 10) + '0';
        carry = digit / 10;
        if (carry == 0) break;
    }

    if (carry > 0) return "1" + s;
    return s;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    int length = str.length();

    string half = str.substr(0, length / 2 + (length % 2));
    string l = half;
    string r = l;
    reverse(r.begin(), r.end());

    if (length % 2 != 0) r = r.substr(1);

    string p1 = l + r;

    if (p1 > str) cout << p1;
    else {        
        string nl = add_one(half);
        string nr = nl;
        reverse(nr.begin(), nr.end());
                
        bool flag = (nl.length() > half.length());

        if (length % 2 != 0 && !flag) nr = nr.substr(1);
        else if (flag) {         
            if (length % 2 == 0) nr = nr.substr(1);
        }
        string p2 = nl + nr;
        cout << p2;
    }

    return 0;
}