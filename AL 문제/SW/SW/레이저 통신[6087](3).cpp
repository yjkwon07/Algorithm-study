#include <cstdio>
#include <queue>
using namespace std;
/*
	������ ���
	https://www.acmicpc.net/problem/6087

	'C'�� 'C' ���̸� �������� �����ϱ� ���� �ʿ��� �ſ��� ������ ���� ������. 
	�ּ��� �ſ��� ��ġ�ؾ� �ϹǷ�, BFS Ž���� ���� �ذ��ϴ� ���� ����. 
	�������� �������� �����̸�, �������� ������ ���� ���ؼ� �ſ��� �ʿ��ϴ�.

	�⺻������ BFS Ž���� �ϵ�, �� �� �̵��� �� �� �� �ִ� ������ �̵��Ѵ�.
	"�� �� �ִ� ������"��, ��('*')�� ������ ������ �Ǵ� ������ ����� �������̴�.
	���� �������� �� ĭ�� �̵��� ������, ���� �̵� �Ÿ��� �����Ѵ�.
	���� �������� �� �� �ִ� �������� ��� �湮 üũ�� �����Ƿ�, 
	�ٸ� �������� ���� ���� �̵� �Ÿ� +1�� ���ָ� �ȴ�.
*/

struct laser {
	int x, y;
};

int w, h, ex, ey = -1;
queue<laser> q;
char a[100][100];
int dist[100][100];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			while (0 <= nx && nx < h && 0 <= ny && ny < w && a[nx][ny] != '*') {
				if (!dist[nx][ny]) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
				nx += dx[i], ny += dy[i];
			}
		}
	}
}

int main() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			scanf(" %1c", &a[i][j]);
			if (a[i][j] == 'C') {
				if (ey == -1) ex = i, ey = j;
				else q.push({ i, j });
			}
		}
	}
	bfs();
	printf("%d\n", dist[ex][ey] - 1);
	return 0;
}


