#include <cstdio>
#include <queue>
using namespace std;
/*
	레이저 통신
	https://www.acmicpc.net/problem/6087

	'C'와 'C' 사이를 레이저로 연결하기 위해 필요한 거울의 개수를 세는 문제다. 
	최소의 거울을 설치해야 하므로, BFS 탐색을 통해 해결하는 것이 좋다. 
	레이저는 직선으로 움직이며, 레이저가 방향을 꺾기 위해서 거울이 필요하다.

	기본적으로 BFS 탐색을 하되, 한 번 이동할 때 갈 수 있는 데까지 이동한다.
	"갈 수 있는 데까지"란, 벽('*')을 만나기 전까지 또는 범위를 벗어나기 전까지이다.
	같은 방향으로 한 칸씩 이동할 때마다, 같은 이동 거리로 저장한다.
	같은 방향으로 갈 수 있는 데까지는 모두 방문 체크를 했으므로, 
	다른 방향으로 가는 곳은 이동 거리 +1을 해주면 된다.
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


