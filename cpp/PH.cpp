#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C, D, E, F, G, H;
int cnt = 0;

bool isValid(const vector<int>& nums) {
    int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
    int e = nums[4], f = nums[5], g = nums[6], h = nums[7];
    int i = nums[8], j = nums[9], k = nums[10], l = nums[11], m = nums[12];

    return (a + e + i + l == A &&
        b + f + j + m == B &&
        c + g + k == C &&
        d + h == D &&
        a + b + c + d == E &&
        e + f + g + h == F &&
        i + j + k == G &&
        l + m == H);
}

// Backtracking function to find valid assignments
void backtrack(vector<int>& nums, vector<bool>& used, int idx) {
    if (idx == 13) {
        // Check the validity of the current assignment
        if (isValid(nums)) {
            cnt++;
        }
        return;
    }

    for (int i = 1; i <= 13; ++i) {
        if (!used[i]) {
            used[i] = true;
            nums[idx] = i;
            backtrack(nums, used, idx + 1);
            used[i] = false; // Backtrack
        }
    }
}

int main() {
    // Input the values A, B, C, D, E, F, G, H
    cin >> A >> B >> C >> D >> E >> F >> G >> H;

    vector<int> nums(13);
    vector<bool> used(14, false); // To track used numbers (1-13)

    backtrack(nums, used, 0);

    // Output the result
    cout << cnt << endl;

    return 0;
}
