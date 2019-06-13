#include <iostream>
#include <queue>
using namespace std;
/*
	로봇
	https://www.acmicpc.net/problem/1726

	로봇이 출발 지점에서 도착 지점까지 이동하기 위해 필요한 최소 명령 횟수를 구하는 문제다. 
	BFS를 통해 최단 거리를 구하는 문제인데, 방향 전환 명령과 이동 명령이 구분되어 있어서 까다롭다.

	이동 명령을 먼저 내리고, 그다음에 방향 전환 명령을 내리는 흐름으로 짜야 한다.
	
	Queue에는 3가지 정보를 넣어야 한다. 
	그 정보는 'x좌표, y좌표, 현재 방향'이다.
	
	방문 여부를 확인하고, 명령 횟수를 저장할 배열 'dist'를 3차원 배열로 선언한다. 
	인덱스는 큐에 들어가는 정보와 같다.
	
	이동 명령은 1, 2, 3 거리로 이동할 수 있으므로, 1칸 이동부터 3칸 이동 순으로 진행한다.
	이동할 때 만약 앞에 벽이 있다면 곧바로 for 문을 break 한다. 
	짧은 거리를 못 가면, 더 긴 거리는 무조건 못 가기 때문이다.
	이후 방문 체크를 하고, 방문하지 않은 곳이라면 큐에 다음 좌표와 현재 방향을 넣는다.
	이동 명령 때는 좌표만 생각하고, 방향은 고정한다.

	그다음은 방향 전환 명령이다. 방향은 동, 서, 남, 북 순서이다. 
	아래 코드에서는 동(0), 서(1), 남(2), 북(3)으로 인덱스를 매겼다.
	방향을 4번 돌리면서, 현재 방향과 다음 방향이 같다면 스킵 한다.
	
	이후 방향 전환을 하는데, 만약 180도 회전이라면 명령을 2번 내린 것이고, 90도 회전이라면 명령을 1번 내린 것이다.
	180도 회전은 동(0)↔서(1), 남(2)↔북(3)인 경우만 있으므로, 이는 (현재방향+다음방향)%4 == 1로 확인할 수 있다. 
	1이라면 180도 회전이고, 1이 아니면 90도 회전이다.
	
	방향 전환 후 방문 체크를 하고, 방문하지 않은 곳이라면 업데이트한다.
	도착지점에 도달할 때까지 이를 반복한다.
*/

#define MAX 110
int map[MAX][MAX];
int dist[MAX][MAX][4];
int n, m;

struct  MOVE
{
	int x, y, dir;
};

int cx, cy, cdir;
int fx, fy, fdir;

const int dx[] = {0, 0, 1, -1 };
const int dy[] = {1, -1, 0, 0 };

void bfs() {
queue<MOVE> qu;
	qu.push({ cx- 1, cy- 1 , cdir -1});
	
	while (!qu.empty())
	{
		int x = qu.front().x, y = qu.front().y, dir = qu.front().dir;
		qu.pop();

		if (x == fx - 1 && y == fy - 1 &&  dir == fdir -1) {
			cout << dist[x][y][dir] << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;  // Same direction.
			int k = (i + dir) % 4 == 1 ? 2 : 1;  // Check rotation. 180 degree (+2), 90 degree (+1)
			if (dist[x][y][i]) continue;   // Already visited.
			qu.push({ x, y, i });
			dist[x][y][i] = dist[x][y][dir] + k;
		}

		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
			if (map[nx][ny]) break;           // Cannot pass the wall.
			if (dist[nx][ny][dir]) continue;  // Already visited.
			qu.push({ nx, ny, dir });
			dist[nx][ny][dir] = dist[x][y][dir] + 1;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cin >> cx >> cy >> cdir;
	cin >> fx >> fy >> fdir;

	bfs();

	return 0;
}