#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll W, H, f, c, x1, y1, x2, y2;

	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

	ll area = W * H, painted = 0;
	ll paintedWidth = x2 - x1;
	ll paintedHeight = y2 - y1;
	ll folded = min(f, W - f);
	ll overlap = 0;

	if (x1 < folded) overlap = min(x2, folded) - x1;

	ll singleWidth = paintedWidth - overlap;
	ll doubleWidth = overlap;

	painted = (singleWidth * 1 + doubleWidth * 2) * paintedHeight * (c + 1);

	cout << area - painted;

	return 0;
}