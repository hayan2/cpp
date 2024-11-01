#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ANGLE = 3600;

struct Segment {
    int start, end;
};

int normalize(int angle) {
    return (angle + MAX_ANGLE) % MAX_ANGLE;
}

bool isInsideSegment(int angle, const Segment& seg) {
    if (seg.start < seg.end) {
        return angle >= seg.start && angle < seg.end;
    }
    else {
        return angle >= seg.start || angle < seg.end;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        segments.push_back({ a, b });
    }

    int p1_angle, p1_distance;
    cin >> p1_angle >> p1_distance;

    int p2_angle, p2_distance;
    cin >> p2_angle >> p2_distance;

    int region_p1 = 0;
    int region_p2 = 0;

    for (const auto& seg : segments) {
        if (isInsideSegment(p1_angle, seg)) {
            region_p1++;
        }
        if (isInsideSegment(p2_angle, seg)) {
            region_p2++;
        }
    }

    if (region_p1 % 2 != region_p2 % 2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
