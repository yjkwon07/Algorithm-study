#include <iostream>
#include <math.h>
using namespace std;
double Answer;

struct Obs {
	int l, r, h;
};

Obs obs[1000];

double getDegree(double y, double x) {
	return atan2(y, x);
}

void proc(int testnum) {
	int r, s, e;
	cin >> r >> s >> e;
	int n;
	cin >> n;
	Answer = e - s;
	for (int i = 0; i<n; i++) {
		cin >> obs[i].l >> obs[i].r >> obs[i].h;
	}

	for (int i = 0; i<n; i++) {
		if (obs[i].h >= r) {
			//r
			Answer += M_PI * r;
			//l
			Answer += 2 * (obs[i].h - r);
			//
			Answer -= 2 * r;
		}
		else {
			double byun = sqrt((2.0*r*obs[i].h) - pow(obs[i].h, 2));
			//r
			Answer += 2.0*getDegree(byun, r - obs[i].h)*r;
			//
			Answer -= 2.0*byun;
		}
	}

	cout << "Case #" << testnum << '\n';
	printf("%.12f\n", Answer);
}

int main() {
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		proc(testcase);
	}
	return 0;
}