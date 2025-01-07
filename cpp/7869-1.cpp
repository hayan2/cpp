#define PI 3.14159265358979
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ������ acos ��� �Լ�
double safe_acos(double x) {
    if (x < -1.0) return PI;   // x�� -1���� ������ ������ PI
    if (x > 1.0) return 0.0;     // x�� 1���� ũ�� ������ 0
    return acos(x);              // x�� [-1, 1] ������ ���������� ���
}

// ���� �����ϴ� ������ ���̸� ����ϴ� �Լ�
double circleIntersectionArea(double x1, double y1, double r1, double x2, double y2, double r2) {
    // �� ���� �߽� �� �Ÿ�
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // ���� ������ ��ġ�� �ʴ� ��� ó��
    if (d >= r1 + r2) {
        return 0.0; // �� ���� ���� ��ġ�� ����
    }
    if (d <= abs(r1 - r2)) {
        // �� ���� �ٸ� �� �ȿ� ������ ���Ե� ���
        double smallerRadius = min(r1, r2);
        return PI * smallerRadius * smallerRadius;
    }

    // ���� ���� ���
    double angle1 = 2 * safe_acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    double angle2 = 2 * safe_acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

    double sectorArea1 = 0.5 * r1 * r1 * (angle1 - sin(angle1));
    double sectorArea2 = 0.5 * r2 * r2 * (angle2 - sin(angle2));

    return sectorArea1 + sectorArea2;
}

int main() {
    // �� 1: �߽� (20, 30), ������ 15
    // �� 2: �߽� (40, 30), ������ 30
    double x1 = 20, y1 = 30, r1 = 15;
    double x2 = 40, y2 = 30, r2 = 30;

    double intersectionArea = circleIntersectionArea(x1, y1, r1, x2, y2, r2);

    cout << fixed << setprecision(6);
    cout << "�� ���� ���� ������ ����: " << intersectionArea << endl;

    return 0;
}