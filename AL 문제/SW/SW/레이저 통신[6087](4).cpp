#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	레이저 통신 
	https://www.acmicpc.net/problem/6087
	3차원 배열로 해결 하기 
*/
#define MAX 100
char arr[MAX][MAX];
int dist[MAX][MAX][MAX]; // x , y ,z(거울 개수)
int r, c;
struct MOVE {
	int x, y, z;
};
MOVE start[2];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int cc;

void print(int z) {
	cout << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << dist[i][j][z] << ' ';
		}
		cout << '\n';
	}
}

void bfs() {
	queue<MOVE> q;
	q.push(start[0]);
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		//		cout << x << y<<'\n';
		//		cout << start[1].x << start[1].y <<'\n';
		if (x == start[1].x && y == start[1].y) {
			//print(z);
			cout << z - 1 << '\n';
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + 1;

			while (0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != '*') {
				if (!dist[nx][ny][nz]) {
					if (!dist[nx][ny][z]) {
						dist[nx][ny][nz] = 1;
						q.push({ nx, ny, nz });
					}
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
}

int main() {
	cin >> c >> r;
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				start[count++] = { i , j, 0 };
			}
		}
	}

	//cout << start[0].x << start[0].y << '\n';
	//cout << start[1].x << start[1].y << '\n';

	//	memset(dist, -1, sizeof(dist));
	bfs();
	return 0;
}