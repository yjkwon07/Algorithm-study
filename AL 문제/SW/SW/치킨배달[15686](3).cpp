#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	치킨배달
	https://www.acmicpc.net/problem/15686
*/
int map[50][50];
int chi[15];
int n, m, ret;

int main() {

	cin >> n >> m;
	int size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				chi[size++] = (i * n) + j;
		}
	}

	ret = 0;
	vector<int> cp(size, 0);
	for (int i = 0; i < m; i++) {
		cp[i] = 1;
	}

	do {

		int t = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					int cnt = 0x7fffffff;
					for (int k = 0; k < size; k++) {
						if (cp[k] == 1) {
							int x, y;
							x = chi[k] / n;
							y = chi[k] % n;
							cnt = min(cnt, abs(i - x) + abs(j - y));
						}
					}
					t += cnt;
				}
			}
		}

		if (ret == 0) ret = t;
		else ret = min(ret, t);
	} while (prev_permutation(cp.begin(), cp.end()));

	cout << ret << '\n';
	return 0;
}