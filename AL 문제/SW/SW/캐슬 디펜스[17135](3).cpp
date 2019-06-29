#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct castle {
	int x, y, z;
	bool operator < (const castle &t) const {
		if (z == t.z) return y > t.y;
		else return z > t.z;
	}
};

int n, m, d, ans;
int a[15][15], archer[3];

void kill() {
	int b[15][15], cnt = 0, t = n;
	memcpy(b, a, sizeof(a));
	while (t--) {
		// Find enemies.
		vector<castle> v;
		for (int k = 0; k<3; k++) {
			priority_queue<castle> q;
			for (int i = 0; i<n; i++) {
				for (int j = 0; j<m; j++) {
					if (b[i][j]) {
						int dist = abs(n - i) + abs(archer[k] - j);
						if (dist <= d) q.push({ i, j, dist });
					}
				}
			}
			if (q.size()) {
				int x = q.top().x, y = q.top().y;
				v.push_back({ x, y });
			}
		}
		// Kill enemies.
		for (int i = 0; i<(int)v.size(); i++) {
			int x = v[i].x, y = v[i].y;
			if (b[x][y]) {
				b[x][y] = 0;
				cnt += 1;
			}
		}
		// Enemies move to down.
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j<m; j++) {
				b[i + 1][j] = b[i][j];
			}
		}
		for (int i = 0; i<m; i++) b[0][i] = 0;
	}
	if (ans < cnt) ans = cnt;
}

void solve() {
	for (int i = 0; i<m; i++) {
		for (int j = i + 1; j<m; j++) {
			for (int k = j + 1; k<m; k++) {
				archer[0] = i, archer[1] = j, archer[2] = k;
				kill();
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	printf("%d\n", ans);
	return 0;
}
