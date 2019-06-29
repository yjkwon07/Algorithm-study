#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
	�볪�� �ű��
	https://www.acmicpc.net/problem/1938
	B ������ �ִ� �볪���� E ������ �Űܾ� �ϴ� ������. 
	�볪���� ���̴� 3���� �����Ǿ� �ְ�, �����¿� �̵��� ȸ�� �̵��� �����ϴ�. 
	���̰� 3�̶�� ����, ȸ���� �����ϴٴ� ���� ������ ������ ������. 
	Ư���� ���̵� �� ���ö� �ټ� �����ϰ� �ڵ��ߴ�.

	�볪���� ���̴� 3���� �����ǹǷ�, ��� ������ �̵� ��ǥ�� ��´�.
	�湮 üũ�� �̵� �Ÿ��� ������ �迭 dist�� 3�������� �����Ѵ�. �ε����� [x ��ǥ] [y ��ǥ] [ȸ�� ����] �̴�.
	ȸ�� ������ ������ �� 0, ������ �� 1�̴�.
	������ �־��� ����ó��, �̵��� �� �ٸ� ����(1)�� ����� �Ѵ�.
	������ ȸ�� ���⿡ ���� �̵� �������� üũ�� �ٸ��� �Ѵ�.
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