#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/*
	장군 
	https://www.acmicpc.net/problem/16509
	왕이 경로에 있다면 retrun
	DFS 방법으로 풀려고 했는데 BFS가 간단 구현 
	경로는 3개의 루트 저장 
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
	// x , y 갱신 
	// 파라미터 전달을 할 때 주소를 전달 했기 때문에 
	// x ,y 값 변경시 참조 변수 변경 
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