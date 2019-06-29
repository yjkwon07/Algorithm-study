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

	알고리즘 분류 : BFS, 브루트 포스
	3차원 미로를 탈출하는 것을 구현해야 한다. 
	단순한 3차원 BFS는, BOJ 7569번 '토마토'처럼 구현하면 된다. 
	하지만, 이 문제는 각 층의 미로가 회전하고, 각 층마다 섞여서 까다롭다. 미로를 제대로 만드는 것이 중요하다.

	미로 맵을 나타낼 3차원 배열의 인덱스는 [층 번호] [X좌표] [Y좌표] 이다.
	각 층을 섞는 것을 순열을 통해 만든다. 별도의 인덱스[0~4]를 만들어서 층을 나타내고, 이를 순열로 섞으면 된다.
	층을 섞은 후, 각 층을 회전해야 한다. 별도의 회전 함수를 만들고, 5중 for문 또는 재귀를 통해 각 층을 순차적으로 회전시킨다.
	첫 층의 출발 칸(0, 0, 0)이 이동할 수 있는 칸[1]인 경우에만 다음 층을 섞는다. 이동할 수 없는 칸[0]이라면 다음 층으로 이동할 수 없기 때문이다.
	층을 순서대로 회전시키면서 마지막 층까지 회전시킨 후, 도착 칸(4, 4, 4)이 이동할 수 있는 칸[1]인지 확인한다. 이동할 수 있는 칸이라면, BFS 탐색을 시작한다.
	BFS 탐색을 할 때마다, 최단 거리 정보를 업데이트한다.

	* 만약 최단 거리가 12로 나왔다면, 이보다 더 짧을 수 없으므로, exit 함수를 통해 프로그램을 바로 종료한다. 
	이 부분을 처리하면 수행 시간을 대폭 줄일 수 있다.
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