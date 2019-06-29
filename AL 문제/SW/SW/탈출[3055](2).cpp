#include <cstdio>
#include <queue>
using namespace std;
/*
	탈출
	https://www.acmicpc.net/problem/3055

	BFS를 통해 고슴도치가 동굴까지 이동하는 최단 거리를 구하는 문제다.
	1분마다 물은 상하좌우로 1칸씩 번지고, 고슴도치도 1칸씩 움직인다.
	고슴도치는 물로 이동할 수 없고, 다음 시간에 물이 차는 곳으로도 갈 수 없다.
	때문에 물을 먼저 Queue에 넣고, 그다음 고슴도치를 Queue에 넣어 BFS를 돌리면 된다.

	Queue에 고슴도치의 위치와 물의 위치가 들어가므로, 물과 고슴도치를 구별할 flag를 만든다.
	map struct의 변수 s가 1인 경우 고슴도치이며, 0인 경우 물이다.
	입력받을 때, 물(*)은 곧바로 Queue에 넣고, 고슴도치(S)는 위치를 기억해둔다.
	입력이 끝난 후, 고슴도치의 위치를 Queue에 넣는다.
	고슴도치와 물은 돌(X)로 이동할 수 없고, 비어있는 칸(.)으로 이동한다.
	dist 배열을 통해 이동거리를 저장하고, 값이 1 이상인 경우 방문한 장소로 기억한다.
	다음 이동에서 동굴(D)을 만나면, s 값을 통해 고슴도치인지 물인지 확인한다.
	물인 경우 무시하고, 고슴도치라면 결과를 출력하고 종료한다.
	Queue가 완전히 빌 때까지 결과를 찾지 못했으면, 동굴에 도착하지 못한 것이므로, KAKTUS를 출력하고 종료한다.
*/
struct map {
	int x, y, s;
	// s represents water(0) or hedgehog(1).
};

int r, c, sx, sy;
char a[51][51];
int dist[51][51];
queue<map> q;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void bfs() {
	// Second, push position of hedgehog.
	q.push({ sx, sy, 1 });
	dist[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, s = q.front().s;
		q.pop();
		for (int i = 0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (a[nx][ny] == 'X' || dist[nx][ny]) continue;
			if (a[nx][ny] == 'D') {
				if (s == 0) continue;       // Water don't flood the cave.
				printf("%d\n", dist[x][y]); // Answer
				return;
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny, s });
		}
	}
	printf("KAKTUS\n");
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			scanf("%1s", &a[i][j]);
			if (a[i][j] == '*') {
				// First, push position of water.
				q.push({ i, j, 0 });
				dist[i][j] = 1;
			}
			else if (a[i][j] == 'S') {
				// Save position of hedgehog.
				sx = i, sy = j;
			}
		}
	}
	bfs();
	return 0;
}