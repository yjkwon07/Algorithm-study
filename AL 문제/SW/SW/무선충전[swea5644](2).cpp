#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

struct BC {
	int x, y, c, p;

	BC() { }
	BC(int _x, int _y, int _c, int _p) : x(_x), y(_y), c(_c), p(_p) { }
};

int testcase;
int m, n;
int ax, ay, ac, bx, by, bc;
int row, col, range, power;
int pa[101];
int pb[101];

int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };

vector<BC> station;

int go() {
	ax = 1; ay = 1; ac = 0;
	bx = 10; by = 10; bc = 0;

	for (int t = 0; t <= m; t++) {
		vector<int> a, b;

		// 사용자들의 BC 구하기
		for (int i = 0; i<station.size(); i++) {
			// 사용자 A
			if (abs(ax - station[i].x) + abs(ay - station[i].y) <= station[i].c) {
				a.push_back(i);
			}

			// 사용자 B
			if (abs(bx - station[i].x) + abs(by - station[i].y) <= station[i].c) {
				b.push_back(i);
			}
		}

		int res = 0;
		int addA = 0;
		int addB = 0;

		// 사용자 A만 충전소를 이용하는 경우
		if (a.size() >= 1 && b.size() == 0) {
			for (int i = 0; i<a.size(); i++) {
				int chargeA = station[a[i]].p;

				if (res < chargeA) {
					res = chargeA;
					addA = chargeA;
				}
			}
		}
		// 사용자 B만 충전소를 이용하는 경우
		else if (a.size() == 0 && b.size() >= 1) {
			for (int i = 0; i<b.size(); i++) {
				int chargeB = station[b[i]].p;

				if (res < chargeB) {
					res = chargeB;
					addB = chargeB;
				}
			}
		}
		// 사용자 A,B 모두 충전소를 이용하는 경우
		else {
			for (int i = 0; i<a.size(); i++) {
				for (int j = 0; j<b.size(); j++) {
					int chargeA = station[a[i]].p;
					int chargeB = station[b[j]].p;

					if (a[i] == b[j]) {
						chargeA /= 2;
						chargeB /= 2;
					}

					if (res < chargeA + chargeB) {
						res = chargeA + chargeB;
						addA = chargeA;
						addB = chargeB;
					}
				}
			}
		}

		ax += dx[pa[t + 1]];
		ay += dy[pa[t + 1]];
		bx += dx[pb[t + 1]];
		by += dy[pb[t + 1]];
		ac += addA;
		bc += addB;
	}

	return ac + bc;
}

int main(int argc, const char * argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++) {
		// 입력
		cin >> m >> n;

		// 사용자 A
		for (int i = 1; i <= m; i++) {
			cin >> pa[i];
		}
		// 사용자 B
		for (int i = 1; i <= m; i++) {
			cin >> pb[i];
		}

		station.clear();

		for (int i = 1; i <= n; i++) {
			cin >> col >> row >> range >> power;
			station.push_back(BC(row, col, range, power));
		}

		cout << "#" << tc << " " << go() << "\n";
	}

	return 0;
}