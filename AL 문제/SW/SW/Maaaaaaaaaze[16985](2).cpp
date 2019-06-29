#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
/*
	Maaaaaaaaaze
	https://www.acmicpc.net/problem/16985
	20ms

	�˰��� �з� : BFS, ���Ʈ ����
	3���� �̷θ� Ż���ϴ� ���� �����ؾ� �Ѵ�. 
	�ܼ��� 3���� BFS��, BOJ 7569�� '�丶��'ó�� �����ϸ� �ȴ�. 
	������, �� ������ �� ���� �̷ΰ� ȸ���ϰ�, �� ������ ������ ��ٷӴ�. �̷θ� ����� ����� ���� �߿��ϴ�.

	�̷� ���� ��Ÿ�� 3���� �迭�� �ε����� [�� ��ȣ] [X��ǥ] [Y��ǥ] �̴�.
	�� ���� ���� ���� ������ ���� �����. ������ �ε���[0~4]�� ���� ���� ��Ÿ����, �̸� ������ ������ �ȴ�.
	���� ���� ��, �� ���� ȸ���ؾ� �Ѵ�. ������ ȸ�� �Լ��� �����, 5�� for�� �Ǵ� ��͸� ���� �� ���� ���������� ȸ����Ų��.
	ù ���� ��� ĭ(0, 0, 0)�� �̵��� �� �ִ� ĭ[1]�� ��쿡�� ���� ���� ���´�. �̵��� �� ���� ĭ[0]�̶�� ���� ������ �̵��� �� ���� �����̴�.
	���� ������� ȸ����Ű�鼭 ������ ������ ȸ����Ų ��, ���� ĭ(4, 4, 4)�� �̵��� �� �ִ� ĭ[1]���� Ȯ���Ѵ�. �̵��� �� �ִ� ĭ�̶��, BFS Ž���� �����Ѵ�.
	BFS Ž���� �� ������, �ִ� �Ÿ� ������ ������Ʈ�Ѵ�.

	* ���� �ִ� �Ÿ��� 12�� ���Դٸ�, �̺��� �� ª�� �� �����Ƿ�, exit �Լ��� ���� ���α׷��� �ٷ� �����Ѵ�. 
	�� �κ��� ó���ϸ� ���� �ð��� ���� ���� �� �ִ�.
*/
struct maze {
	int x, y, z;
};

int a[5][5][5], b[5][5][5], d[5];
int dist[5][5][5], ans = 1e9;
const int dx[] = { 1, -1, 0, 0, 0, 0 }, dy[] = { 0, 0, 1, -1, 0, 0 }, dz[] = { 0 ,0, 0, 0, 1, -1 };

void bfs() {
	queue<maze> q;
	q.push({ 0, 0, 0 });
	memset(dist, -1, sizeof(dist));
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z; q.pop();
		if (x == 4 && y == 4 && z == 4) {
			ans = min(ans, dist[x][y][z]);
			if (ans == 12) {
				printf("12\n");
				exit(0);
			}
			return;
		}
		for (int i = 0; i<6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (b[nx][ny][nz] && dist[nx][ny][nz] == -1) {
				q.push({ nx, ny, nz });
				dist[nx][ny][nz] = dist[x][y][z] + 1;
			}
		}
	}
}

void rotate(int s) {
	int temp[5][5];
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			temp[j][4 - i] = b[s][i][j];
		}
	}
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			b[s][i][j] = temp[i][j];
		}
	}
}

void solve() {
	do {
		for (int i = 0; i<5; i++) {
			memcpy(b[d[i]], a[i], sizeof(a[i]));
		}
		for (int i = 0; i<4; i++) {
			rotate(0);
			if (!b[0][0][0]) continue;
			for (int j = 0; j<4; j++) {
				rotate(1);
				for (int k = 0; k<4; k++) {
					rotate(2);
					for (int m = 0; m<4; m++) {
						rotate(3);
						for (int n = 0; n<4; n++) {
							rotate(4);
							if (b[4][4][4]) bfs();
						}
					}
				}
			}
		}
	} while (next_permutation(d, d + 5));
}

int main() {
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			for (int k = 0; k<5; k++) {
				scanf("%d", &a[i][j][k]);
			}
		}
	}
	for (int i = 0; i<5; i++) d[i] = i;
	solve();
	printf("%d\n", ans == 1e9 ? -1 : ans);
	return 0;
}