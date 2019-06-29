#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
/*
	Ä³½½ µðÆæ½º
	https://www.acmicpc.net/problem/17135
	28ms
*/
int n, m, d;
int ret;
int map[30][30];
int backup[30][30];

struct PO {
	int y, x, dist;
	bool operator < (const PO &t) const {
		if (dist == t.dist) return x > t.x;
		else return dist > t.dist;
	}
};
vector<PO> defense;

void copy_arr() {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			backup[i][j] = map[i][j];
		}
	}
}

void check() {
	bool ok = true;
	int ans = 0;
	int t = n;

	while (t--) {
		ok = false;
		vector<PO> a;

		for (int k = 0; k < 3; k++) {
			PO po = defense[k];
			priority_queue<PO> q;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (backup[i][j]) {
						ok = true;
						int dist = abs(n - i) + abs(po.x - j);
						if (d >= dist) {
							q.push({ i, j, dist });
						}
					}
				}
			}

			if (q.size()) {
				PO po = q.top();
				a.push_back(po);
			}
		}

		for (int i = 0; i < (int)a.size(); i++) {
			PO po = a[i];
			if (backup[po.y][po.x]) {
				backup[po.y][po.x] = 0;
				ans++;
			}
		}

		// down 
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				backup[i + 1][j] = backup[i][j];
			}
		}

		for (int i = 0; i < m; i++) {
			backup[0][i] = 0;
		}
	}
	if (ret < ans) ret = ans;
}

void dfs(int count, int sy, int sx) {
	if (count == 3) {
		copy_arr();
		check();
		return;
	}

	for (int i = sy; i < n + 1; i++) {
		for (int j = sx; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 2;
				defense.push_back({ i , j , 0 });
				dfs(count + 1, i, j);
				map[i][j] = 0;
				defense.pop_back();
			}
		}
		sx = 0;
	}
}

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, n, 0);
	cout << ret << '\n';
	cin >> n;
	return 0;
}