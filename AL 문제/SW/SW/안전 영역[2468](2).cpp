#include <cstdio>
#include <cstring>
using namespace std;
/*
	DFS
	���� ����
	https://www.acmicpc.net/problem/2468

	���� ����� �ʴ� ���� ������ �ִ� ������ ���ϴ� ������. 
	DFS�� ������ ���� Ž���ϸ鼭, ������ ������ �� �� �ִ�.

	�Է����� �־����� ������ ���� ū ���� M�̶� �д�.
	0���� M-1���� ���� ���� K�� �ø��鼭 DFS�� ������.
	DFS�� Ž���� ��, ����� �ʴ� ����(���� K �ʰ�)���� �̵��Ѵ�. �̵��ϸ鼭 �湮 üũ�� �صд�.
	���� �湮���� ���� ���̸鼭 ���̰� K���� ���ٸ�, �ٽ� DFS�� Ž���Ѵ�.
	N*N �������� ���� ��� �湮 üũ�ߴٸ�, ���� ���̸� 1 �ø��� �ٽ� DFS�� �ݺ��Ѵ�.
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