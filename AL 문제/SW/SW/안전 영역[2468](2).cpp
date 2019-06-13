#include <cstdio>
#include <cstring>
using namespace std;
/*
	DFS
	안전 영역
	https://www.acmicpc.net/problem/2468

	물에 잠기지 않는 안전 영역의 최대 개수를 구하는 문제다. 
	DFS로 영역을 완전 탐색하면서, 영역의 개수를 셀 수 있다.

	입력으로 주어지는 값에서 가장 큰 값을 M이라 둔다.
	0부터 M-1까지 제한 높이 K를 올리면서 DFS를 돌린다.
	DFS로 탐색할 때, 잠기지 않는 영역(높이 K 초과)으로 이동한다. 이동하면서 방문 체크를 해둔다.
	아직 방문하지 않은 곳이면서 높이가 K보다 높다면, 다시 DFS로 탐색한다.
	N*N 사이즈의 맵을 모두 방문 체크했다면, 제한 높이를 1 올리고 다시 DFS를 반복한다.
*/
struct cheese {
	int x, y;
};

int n, m, ans;
int a[100][100];
bool check[100][100];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y, int z) {
	check[x][y] = true;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (check[nx][ny] || a[nx][ny] <= z) continue;
		dfs(nx, ny, z);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &a[i][j]);
			if (m < a[i][j]) m = a[i][j];
		}
	}
	for (int k = 0; k<m; k++) {
		memset(check, false, sizeof(check));
		int cnt = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (!check[i][j] && a[i][j] > k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		if (ans < cnt) ans = cnt;
	}
	printf("%d\n", ans);
	return 0;
}