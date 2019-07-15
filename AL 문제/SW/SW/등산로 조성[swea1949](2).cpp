#include <iostream>
#include <math.h>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
/*
	���� ����
	DFS + ��Ʈ��ŷ�� �̿��Ͽ� ��� ��츦 Ž���ϴ� ����Ž�� �����̴�
	���� ���츮�� �ִ� 5���̹Ƿ� �� �������� ��� ��츦 Ž���Ѵ�

	���� �ڱ⺸�� ���̰� ���ų� ���� ���츮�� ������ ���, ���� ���θ� �ѹ��� ������ ���� ���ٸ� �ش� ������ ��´�

	������ �ִ� ���̴� 21 ���� ���� �� �ִ�
*/
int testcase;
int n, k;
int ans, highest;
int map[8][8];
int visited[8][8];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int cnt, int cut) {
	// �ִ밪 ����
	ans = max(ans, cnt);

	// DFS Ž��
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// �� ���� ����ٸ�
		if (nx<0 || ny<0 || nx >= n || ny >= n) continue;

		// �̹� �湮�� �����̶��
		if (visited[nx][ny]) continue;

		// ���� �������� ���ų� ���� ������ ���� ���
		if (map[x][y] <= map[nx][ny]) {
			if (cut == 0) {
				// ������ 1 ~ k ��ŭ ��Ƴ���
				for (int depth = 1; depth <= k; depth++) {
					int tmp = map[nx][ny];
					int land = map[nx][ny] - depth;

					// ���� ���� ������ ���� �������� ���ٸ�
					if (map[x][y] > land) {
						visited[nx][ny] = true;
						map[nx][ny] = land;
						dfs(nx, ny, cnt + 1, cut + 1);
						map[nx][ny] = tmp;
						visited[nx][ny] = false;
					}
				}
			}
		}
		// ���� �������� ���� ������ ���� ���
		else {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, cut);
			visited[nx][ny] = false;
		}
	}
}

int main(int argc, const char * argv[]) {
	// cin,cout �ӵ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> k;

		highest = 0;

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cin >> map[i][j];

				// ���� ���� ������ ���̸� ����
				highest = max(highest, map[i][j]);
			}
		}

		memset(visited, false, sizeof(visited));

		ans = 0;

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				// ���� �湮���� ���� ���� ���� ������ ��� Ž�� ����
				if (map[i][j] == highest && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j, 1, 0);
					visited[i][j] = false;
				}
			}
		}

		// ���� ���
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}