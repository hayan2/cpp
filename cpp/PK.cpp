#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sol(vector<char>& slots) {
    int whiteCnt = 0, blueCnt = 0;

    for (char slot : slots) {
        if (slot == 'W') {
            whiteCnt++;
        }
        else if (slot == 'B') {
            blueCnt++;
        }
    }

    int index = 0;

    for (int i = 0; i < whiteCnt; i++) {
        slots[index++] = 'W';
    }

    for (int i = index; i < index + (slots.size() - whiteCnt - blueCnt); i++) {
        slots[i] = 'E';
    }
    index += (slots.size() - whiteCnt - blueCnt);

    for (int i = 0; i < blueCnt; i++) {
        slots[index++] = 'B';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s;
    cin >> s;
    vector<char> slots(s);

    for (int i = 0; i < s; i++) {
        cin >> slots[i];
    }

    sol(slots);

    for (char slot : slots) {
        cout << slot << " ";
    }
    cout << endl;

    return 0;
}
