#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double X, Y, D, T;	

	cin >> X >> Y >> D >> T;

	double walk, jump, mixed, dist, leftOver;
	
	dist = sqrt(X * X + Y * Y);

	walk = dist;
	leftOver = fmod(dist, D);
	
	if (!leftOver) {
		// use only walk or use only jump
		jump = dist / D;
		cout << min(walk, jump);
	}
	else {
		// can't get to destination just by jumping
		
	}
	

	return 0;
}