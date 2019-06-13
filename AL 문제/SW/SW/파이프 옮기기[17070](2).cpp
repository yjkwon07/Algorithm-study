#include <cstdio>
/*
	파이프 옮기기 
	https://www.acmicpc.net/problem/17070
*/
int n, ans;
int a[16][16];
int dx[] = { 0, 1, 1 }, dy[] = { 1, 0, 1 };

void solve(int x, int y, int z) {
	if (x == n - 1 && y == n - 1) {
		ans += 1;
		return;
	}

	for (int i = 0; i<3; i++) {
		if (i + z == 1) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || ny >= n || a[nx][ny]) continue;
		if (i == 2 && (a[x][y + 1] || a[x + 1][y])) continue;
		solve(nx, ny, i);
	}
}

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	solve(0, 1, 0);
	printf("%d\n", ans);
	scanf_s("%d", ans);
	return 0;
}
