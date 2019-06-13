#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/*
	�屺 
	https://www.acmicpc.net/problem/16509
	���� ��ο� �ִٸ� retrun
	DFS ������� Ǯ���� �ߴµ� BFS�� ���� ���� 
	��δ� 3���� ��Ʈ ���� 
*/
struct grid {
	int x, y;
};

int sx, sy, ex, ey;
int dist[10][9];

const int dx[8][3] = {
	{ -1, -2, -3 },
	{ -1, -2, -3 },
	{ 0, -1, -2 },
	{ 0, -1, -2 },
	{ 0, 1, 2 },
	{ 0, 1, 2 },	
	{ 1, 2, 3 },
	{ 1, 2, 3 } 
};

const int dy[8][3] = {
	{ 0, -1, -2 },
    { 0, 1, 2 },
	{ -1, -2, -3 },
	{ 1, 2, 3 },
	{ -1, -2, -3 },
	{ 1, 2, 3 },
	{ 0, -1, -2 },
	{ 0, 1, 2 } 
};

bool move(int i, int &x, int &y) {
	int nx = x, ny = y;
	for (int j = 0; j<3; j++) {
		nx = x + dx[i][j], ny = y + dy[i][j];
		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 9) return false;
		if (j < 2 && nx == ex && ny == ey) return false;
	}
	// x , y ���� 
	// �Ķ���� ������ �� �� �ּҸ� ���� �߱� ������ 
	// x ,y �� ����� ���� ���� ���� 
	x = nx, y = ny;
	return true;
}

void bfs() {
	queue<grid> q;
	q.push({ sx, sy });
	dist[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		if (x == ex && y == ey) {
			printf("%d\n", dist[x][y]);
			return;
		}
		for (int i = 0; i<8; i++) {
			int nx = x, ny = y;
			if (move(i, nx, ny) && dist[nx][ny] == -1) {
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	printf("-1\n");
}

int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &ex, &ey);
	bfs();
	return 0;
}