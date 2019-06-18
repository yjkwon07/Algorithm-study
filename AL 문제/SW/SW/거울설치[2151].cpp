#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	* 레이저 통신과 유사(BFS 기준)
	
	거울설치
	https://www.acmicpc.net/problem/2151

	문에서 다른 문까지 빛으로 연결하기 위해 필요한 거울의 최소 개수를 구하는 문제다. 
	빛은 거울에서만 꺾이고, 거울은 45도 각도로 설치할 수 있다. 
	거울을 적절히 설치해서 문에서 문으로 빛을 연결해야 한다.

	문('#')은 항상 2개만 주어지므로, 하나의 문을 시작점으로, 다른 하나의 문은 도착점으로 둔다.
	BFS 탐색을 하면서 다음 이동 좌표가 갈 수 있는 곳인지 확인한다.
	방문 체크와 거울 설치 횟수를 저장할 배열 dist를 3차원으로 선언한다.
	dist의 인덱스는 [X 좌표] [Y좌표] [이동 방향] 이다.
	만약 다음 이동 좌표가 맵의 밖이거나 벽('*')이라면, 이동할 수 없다.
	다음 이동 좌표가 빈 공간('.')이라면, 계속 이동한다.
	while 반복문을 통해 다음 이동이 가능한 위치라면, 같은 방향으로 계속 이동한다.
	이동하다가 거울을 놓을 수 있는 장소('!')에 도착하면, 다음 이동 좌표로 3가지를 큐에 넣는다.
	첫 번째, 이전 이동 방향과 같은 방향의 좌표를 넣는다. (거울 설치를 하지 않는다.)
	두 번째, 방향을 +90도로 꺾는 좌표를 넣는다. (거울을 설치한다.)
	세 번째, 방향을 -90도로 꺾는 좌표를 넣는다. (거울을 설치한다.)
	위 과정을 도착지점에 도착할 때까지 반복한다.

	거울을 꺾는 방향 이동은 아래와 같이 나타낼 수 있다.
	우선 방향은 [↑0  ↓1  ←2  →3 ] 으로 둔다.
	위쪽(0) 방향은 왼쪽(2)이나 오른쪽(3)으로 꺾인다. [ 0 → 2 , 0 → 3 ]
	아래쪽(1) 방향은 왼쪽(2)이나 오른쪽(3)으로 꺾인다. [ 1 → 2 , 1 → 3 ]
	왼쪽(2) 방향은 위쪽(0)이나 아래쪽(1)으로 꺾인다. [ 2 → 0 , 2 → 1 ]
	오른쪽(3) 방향은 위쪽(0)이나 아래쪽(1)으로 꺾인다. [ 3 → 0 , 3 → 1 ]
*/
#define MAX 50
char arr[MAX][MAX];
int n;
int dist[MAX][MAX][4]; // 좌표 , dir
const int dx[] = { -1 , 1 , 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct MOVE {
	int x, y, z;
};
int ex, ey;
queue<MOVE> qu;

bool out(int nx, int ny, int z) {
	if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
	if (arr[nx][ny] == '*') return false;
	return true;
}

void bfs() {
	while (!qu.empty())
	{
		int x = qu.front().x;
		int y = qu.front().y;
		int z = qu.front().z;
		qu.pop();

		// find
		if (x == ex && y == ey) {
			printf("%d\n", dist[x][y][z]);
			return;
		}

		// search		
		int nx = x + dx[z];
		int ny = y + dy[z];

		while (out(nx, ny, z) && arr[nx][ny] == '.') {
			nx += dx[z];
			ny += dy[z];
		}

		if (out(nx, ny, z) && arr[nx][ny] == '!') {
			dist[nx][ny][z] = dist[x][y][z];
			qu.push({ nx, ny , z });

			int k = z < 2 ? 2 : 0;
			for (int i = k; i<k + 2; i++) {
				if (dist[nx][ny][i] == -1) {
					dist[nx][ny][i] = dist[x][y][z] + 1;
					qu.push({ nx, ny, i });
				}
			}
		}
	}
}

void print() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j <n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	scanf("%d", &n);
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == '#') {
				if (qu.empty()) {
					for (int k = 0; k<4; k++) {
						qu.push({ i, j, k });
						dist[i][j][k] = 0;
					}
				}
				else {
					ex = i, ey = j;
				}
				arr[i][j] = '!';
			}
		}
	}

	// print();
	bfs();
	return 0;
}