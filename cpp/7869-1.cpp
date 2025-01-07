#define PI 3.14159265358979
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 안전한 acos 계산 함수
double safe_acos(double x) {
    if (x < -1.0) return PI;   // x가 -1보다 작으면 각도는 PI
    if (x > 1.0) return 0.0;     // x가 1보다 크면 각도는 0
    return acos(x);              // x가 [-1, 1] 범위면 정상적으로 계산
}

// 원이 교차하는 영역의 넓이를 계산하는 함수
double circleIntersectionArea(double x1, double y1, double r1, double x2, double y2, double r2) {
    // 두 원의 중심 간 거리
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // 원이 완전히 겹치지 않는 경우 처리
    if (d >= r1 + r2) {
        return 0.0; // 두 원이 서로 겹치지 않음
    }
    if (d <= abs(r1 - r2)) {
        // 한 원이 다른 원 안에 완전히 포함된 경우
        double smallerRadius = min(r1, r2);
        return PI * smallerRadius * smallerRadius;
    }

    // 교차 영역 계산
    double angle1 = 2 * safe_acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    double angle2 = 2 * safe_acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

    double sectorArea1 = 0.5 * r1 * r1 * (angle1 - sin(angle1));
    double sectorArea2 = 0.5 * r2 * r2 * (angle2 - sin(angle2));

    return sectorArea1 + sectorArea2;
}

int main() {
    // 원 1: 중심 (20, 30), 반지름 15
    // 원 2: 중심 (40, 30), 반지름 30
    double x1 = 20, y1 = 30, r1 = 15;
    double x2 = 40, y2 = 30, r2 = 30;

    double intersectionArea = circleIntersectionArea(x1, y1, r1, x2, y2, r2);

    cout << fixed << setprecision(6);
    cout << "두 원의 교차 영역의 넓이: " << intersectionArea << endl;

    return 0;
}