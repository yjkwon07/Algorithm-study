#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/*
	PuyoPuyo
	�˰��� �з� : BFS, �ùķ��̼�

	���� '�ѿ� �ѿ�'�� ���α׷����ϴ� ������. 
	�־��� �ѿ�ѿ� �ǿ��� �󸶳� ���� ���Ⱑ �Ͼ���� ����� �Ѵ�. 
	BFS�� ���� ��ü Ž���� �ϰ�, ��Ʈ�� �� �ִ� ����� �ִ��� Ȯ���ϸ鼭, 4�� �̻��̸� ��Ʈ���� �Ʒ��� ����߸��� �ȴ�.


	1. �Ʒ��������� ���(R,G,B,P,Y)�� Ȯ���Ѵ�. �� ����(.)�� �����Ѵ�.
	2. ����� �߰��ϸ�, BFS Ž���� ���� ���� ������ ����� �� ���� �������ִ��� Ȯ���Ѵ�.
	3. ���� ������ ����� 4�� �̻��̸�, ���� ����� ����� ��� ��Ʈ����. ��Ʈ�� ����� �� �������� �����.
	4. ���� ������ 1~3 ������ �ݺ��Ѵ�.
	5. ���� ����� �� ���̶� �����ٸ�, ���� ī��Ʈ�� 1 ������Ű��, �Ʒ��� ������ �� �ִ� ����� �ִ��� Ȯ���ϰ� ����߸���.
	����� �� ���̶� �����ٸ�, 1~5 ������ �ݺ��Ѵ�. ���� �� ���� �� �����ٸ� ���α׷��� �����Ѵ�.
*/
struct puyo {
	int x, y;
};

const int n = 12, m = 6;
char a[n][m + 1];
bool check[n][m + 1];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void fall() {
	// Puyo blocks fall down.
	for (int j = 0; j<m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == '.') continue;
			for (int k = n - 1; k >= i; k--) {
				if (a[k][j] == '.') {
					a[k][j] = a[i][j];
					a[i][j] = '.';
				}
			}
		}
	}
}

bool bfs(int i, int j, char c) {
	queue<puyo> q;
	vector<puyo> block;
	q.push({ i, j });
	check[i][j] = true;
	block.push_back({ i, j });
	// Count same blocks
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny] || a[nx][ny] != c) continue;
			check[nx][ny] = true;
			block.push_back({ nx, ny });
			q.push({ nx, ny });
		}
	}
	// Crash blocks if block >= 4
	if ((int)block.size() >= 4) {
		for (auto k : block) a[k.x][k.y] = '.';
		return true;
	}
	else return false;
}

bool crash() {
	// Find out if exist blocks which can be crashed.
	bool crashed = false;
	memset(check, false, sizeof(check));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (check[i][j] || a[i][j] == '.') continue;
			if (bfs(i, j, a[i][j])) crashed = true;
		}
	}
	return crashed;
}

void solve() {
	int ans = 0;
	while (crash()) {
		fall();
		ans += 1;
	}
	printf("%d\n", ans);
}

int main() {
	for (int i = 0; i<n; i++) scanf("%s", a[i]);
	solve();
	return 0;
}