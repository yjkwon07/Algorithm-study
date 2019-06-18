#include <cstdio>
#include <vector>
#include <set>
using namespace std;
/*
	�� �μ��� �̵��ϱ�4
	https://www.acmicpc.net/problem/16946
	
	�˰��� �з� : DFS, BFS  

	�� �μ��� �̵��ϱ� �� ��° ������. �̹� ������ ���� ������� ������ �ٸ���. �÷��� �� �˰����� �����ϴ� �����̴�.

	�⺻ ���̵��
	�⺻������, �� ��(1)���� DFS�� �����Ͽ� ��ĭ(0)�� ���� ������� ����� ������ �� �ִ�.
	������ ����������, �ִ� 1000*1000 ����� �Է����� �־����Ƿ� �ð� �ʰ��� ����.

	���� ���̵��
	�迭 A�� DFS�� ���� ���� Ž���Ѵ�.
	1. ��ĭ(0)���� �����Ͽ� ������ ��ĭ�� ������ ��� ���鼭 ����Ʈ V�� ����صд�.
	2. ��ĭ�� ������ �� ��, �迭 B�� �� ��ĭ���� �ѹ����� �صд�.
	1~2 ������ �� ��ü�� �Ѵ�.
	�迭 A���� �� ��(1)���� ������ 4ĭ�� Ȯ���ϰ�, �迭 B�� ���� �����ص� �ѹ����� �ִ��� Ȯ���Ѵ�.
	Set �ڷᱸ���� ���� �ߺ��� ������ ������ �ѹ����� ����صд�.
	�� ��(1)���� �ѹ����� �ش��ϴ� ����Ʈ V�� ���� ��� ���Ѵ�.
*/
int n, m;
int a[1001][1001], b[1000][1000];
bool check[1000][1000];
vector<int> v;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int dfs(int x, int y, int z) {
	b[x][y] = z;
	int ret = 1;
	check[x][y] = true;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (!check[nx][ny] && !a[nx][ny]) ret += dfs(nx, ny, z);
	}
	return ret;
}

void solve() {
	// Flood-fill
	int z = 1;
	v.push_back(0);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (!a[i][j] && !check[i][j]) {
				v.push_back(dfs(i, j, z));
				z += 1;
			}
		}
	}
	// Add sum to wall
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j]) {
				set<int> s;
				for (int k = 0; k<4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					s.insert(b[ni][nj]);
				}
				for (auto k : s) a[i][j] += v[k];
			}
		}
	}
	// Print
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			printf("%d", a[i][j] % 10);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	solve();
	return 0;
}