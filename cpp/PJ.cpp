#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to check if we can fit two non-penetrating rectangular rings of width w
bool can_fit(const vector<pair<int, int>>& points, int w) {
    int n = points.size();
    if (n == 0) return true;

    // Sort points based on x-coordinates
    vector<pair<int, int>> sorted_points = points;
    sort(sorted_points.begin(), sorted_points.end());

    for (int i = 0; i <= n; ++i) {
        // Group 1: points from 0 to i-1
        int min_x1 = (i > 0) ? numeric_limits<int>::max() : 0;
        int max_x1 = (i > 0) ? numeric_limits<int>::min() : 0;
        int min_y1 = (i > 0) ? numeric_limits<int>::max() : 0;
        int max_y1 = (i > 0) ? numeric_limits<int>::min() : 0;

        for (int j = 0; j < i; ++j) {
            min_x1 = min(min_x1, sorted_points[j].first);
            max_x1 = max(max_x1, sorted_points[j].first);
            min_y1 = min(min_y1, sorted_points[j].second);
            max_y1 = max(max_y1, sorted_points[j].second);
        }

        // Group 2: points from i to n-1
        int min_x2 = (i < n) ? numeric_limits<int>::max() : 0;
        int max_x2 = (i < n) ? numeric_limits<int>::min() : 0;
        int min_y2 = (i < n) ? numeric_limits<int>::max() : 0;
        int max_y2 = (i < n) ? numeric_limits<int>::min() : 0;

        for (int j = i; j < n; ++j) {
            min_x2 = min(min_x2, sorted_points[j].first);
            max_x2 = max(max_x2, sorted_points[j].first);
            min_y2 = min(min_y2, sorted_points[j].second);
            max_y2 = max(max_y2, sorted_points[j].second);
        }

        // Check if the two outer rectangles can be non-penetrating
        if (i > 0 && i < n) {
            int outer1_left = min_x1 - w;
            int outer1_right = max_x1 + w;
            int outer1_bottom = min_y1 - w;
            int outer1_top = max_y1 + w;

            int outer2_left = min_x2 - w;
            int outer2_right = max_x2 + w;
            int outer2_bottom = min_y2 - w;
            int outer2_top = max_y2 + w;

            // Check if they are non-penetrating
            if (outer1_right < outer2_left || outer2_right < outer1_left ||
                outer1_top < outer2_bottom || outer2_top < outer1_bottom) {
                return true;
            }
        }
    }
    return false;
}

// Binary search to find the minimum possible larger width
int min_larger_width(vector<pair<int, int>>& points) {
    int left = 0, right = 1e6;  // Arbitrary large value for width
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_fit(points, mid)) {
            answer = mid;  // Update answer if fitting is possible
            right = mid - 1;  // Try for a smaller width
        }
        else {
            left = mid + 1;  // Increase the width
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Output the result
    cout << min_larger_width(points) << endl;

    return 0;
}
