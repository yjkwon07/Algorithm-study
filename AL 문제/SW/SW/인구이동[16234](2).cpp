#include<cstdio>
#include<cstring>
#define abs(x) (((x) > 0) ? (x) : (- (x)))
using namespace std;
/*
	rebas
	���� ����

	�˰��� �з�: DFS

	������ ���� ���� ������ ���� �α� �̵��� �ϴ� ������.
	������ ������ �� ���� ���� �α� ���̰� L �̻�, R ������ ����
	�����ϴ�. �α� ���̰� �� ������ ����ٸ� ������ �� �� ����,
	�α� �̵��� �� �� ����. �� ������ �׷������� ���� ��� ������ ã�� ������ ����ϴ�.

	- DFS�� ���� ���� ������ ������ �� ������ ã�´�. (1, 1)���� (N, N)���� ��ü ������ Ž���ϸ鼭
	�湮���� ���� ������� DFS�� ȣ���Ѵ�.
	- DFS Ž���� �����ϸ鼭 ���� ������ ������ �ִٸ�, ���� ���� ������ ī��Ʈ �ϰ�, �α� ���� ���� �����Ѵ�.
	- ���� DFS Ž���� �ϸ鼭 ������ ���� ������ ��θ� ����صд�.
	�Ʒ� �ҽ��ڵ忡���� moving�̶�� �̸��� �迭�� ����ߴ�.
	- �� ���� DFS Ž���� ������, ī��Ʈ�� 1�� �Ѵ��� Ȯ���Ѵ�.
	ī��Ʈ�� 1�� �Ѵ´ٸ� ���� ������ ������ �ִ� ���̹Ƿ�, �α��� �̵���Ų��.
	- �� ������ �ݺ��ϸ鼭, �α� �̵��� ��ȭ�� ���ٸ� �����Ѵ�.

*/
struct nation {
	int x, y;
};

int n, l, r, cnt, ans;
int a[50][50];
bool check[50][50], moving[50][50];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0 ,-1 };

int dfs(int x, int y) {
	check[x][y] = true;
	int population = a[x][y];
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		int diff = abs(a[x][y] - a[nx][ny]);
		if (diff <  l || diff > r || check[nx][ny]) continue;
		moving[nx][ny] = true;
		cnt++;
		population += dfs(nx, ny);
	}
	return population;
}

void migrate(int p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (moving[i][j]) {
				a[i][j] = p;
				moving[i][j] = false;
			}
		}
	}
}

void solve() {
	int ans = 0;
	while (true) {
		bool moved = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					cnt = 1;
					int population = dfs(i, j) / cnt;
					if (cnt > 1) {
						a[i][j] = population;
						migrate(population);
						moved = true;
					}
				}
			}
		}
		if (moved) ans++;
		else break;
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	return 0;
}