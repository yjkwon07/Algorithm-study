#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
	통나무 옮기기
	https://www.acmicpc.net/problem/1938
	B 지점에 있는 통나무를 E 지점에 옮겨야 하는 문제다. 
	통나무의 길이는 3으로 고정되어 있고, 상하좌우 이동과 회전 이동이 가능하다. 
	길이가 3이라는 점과, 회전이 가능하다는 점이 굉장히 귀찮은 문제다. 
	특별한 아이디어가 안 떠올라서 다소 무식하게 코딩했다.

	통나무의 길이는 3으로 고정되므로, 가운데 정점을 이동 좌표로 삼는다.
	방문 체크와 이동 거리를 저장할 배열 dist를 3차원으로 선언한다. 인덱스는 [x 좌표] [y 좌표] [회전 방향] 이다.
	회전 방향은 가로일 때 0, 세로일 때 1이다.
	문제에 주어진 조건처럼, 이동할 때 다른 나무(1)이 없어야 한다.
	나무의 회전 방향에 따라 이동 가능한지 체크를 다르게 한다.
*/

#define MAX 50
struct STATE {
	int x, y, dir;
	// middle address
	// turn_direction
	// 0 -> -
	// 1 -> |
};
queue<STATE> q;

char arr[MAX][MAX];
int dist[MAX][MAX][2];
int N, ans;
const int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
const int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

// MAX: ranage
bool out(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

// wall check
bool check(int x, int y) {
	if (!out(x, y) && arr[x][y] != '1') return true;
	else return false;
}

// wall check just one && out
void one(int x, int y, int z, int dx, int dy) {
	if (!out(x + dx, y + dy) && arr[x + dx][y + dy] != '1' && dist[x][y][z] == -1) {
		q.push({ x, y, z });
		dist[x][y][z] = dist[x - dx][y - dy][z] + 1;
	}
}

// wall check Three point && out
void three(int x, int y, int z, int nx, int ny, int dx, int dy) {
	if (!out(nx, ny) && dist[nx][ny][z] == -1) {
		if (arr[nx][ny] != '1' && arr[nx - dx][ny - dy] != '1' && arr[nx + dx][ny + dy] != '1') {
			q.push({ nx, ny, z });
			dist[nx][ny][z] = dist[x][y][z] + 1;
		}
	}
}

// rotate check
void rotate(int x, int y, int z) {
	for (int i = 0; i<8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!check(nx, ny)) return;
	}

	if (dist[x][y][!z] == -1) {
		q.push({ x, y, !z });
		// z -> 0 || 1 
		dist[x][y][!z] = dist[x][y][z] + 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().dir; q.pop();
		int mx = 0, my = 0;
		if (z) mx = 1;
		else my = 1;

		// check end point 
		if (arr[x][y] == 'E' && arr[x - mx][y - my] == 'E' && arr[x + mx][y + my] == 'E') {
			printf("%d\n", dist[x][y][z]);
			return;
		}

		// heigh
		if (z) {
			// Up
			one(x - 1, y, z, -1, 0);
			// Down 
			one(x + 1, y, z, 1, 0);
			// Right
			three(x, y, z, x, y + 1, mx, my);
			// Left
			three(x, y, z, x, y - 1, mx, my);
			// Turn 
			rotate(x, y, z);
		}
		// width
		else {
			// Left
			one(x, y - 1, z, 0, -1);
			// Right
			one(x, y + 1, z, 0, 1);
			// Down
			three(x, y, z, x + 1, y, mx, my);
			// Up
			three(x, y, z, x - 1, y, mx, my);
			// Turn
			rotate(x, y, z);
		}
	}
	printf("0\n");
}

int main() {
	scanf("%d", &N);
	memset(dist, -1, sizeof(dist));
	vector<STATE> v;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'B') v.push_back({ i, j });
		}
	}
	int x = v[1].x, y = v[1].y, z = v[0].x != v[1].x;
	q.push({ x, y, z });
	dist[x][y][z] = 0;
	bfs();
	return 0;
}