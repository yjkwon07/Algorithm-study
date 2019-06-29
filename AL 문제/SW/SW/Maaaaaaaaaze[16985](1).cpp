#include<iostream>
#include <cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
/*
	Maaaaaaaaaze
	https://www.acmicpc.net/problem/16985
*/

#define MAX 5
int ans = 9999;
int arr[4][MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int maze[MAX][MAX][MAX];

struct MOVE {
	int x, y, z;
};

void rotate() {
	for (int k = 0; k < 5; k++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				arr[1][k][x][y] = arr[0][k][4 - y][x];
			}
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				arr[2][k][x][y] = arr[1][k][4 - y][x];
			}
		}
		
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				arr[3][k][x][y] = arr[2][k][4 - y][x];
			}
		}
	}
}

void bfs() {
	if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return;
	memset(dist, -1, sizeof(dist));
	queue<MOVE> qu;
	qu.push({ 0, 0 ,0 });
	dist[0][0][0] = 0;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int z = qu.front().z;
		qu.pop();

		if (x == 4 && y == 4 && z == 4) {
			if (ans > dist[z][x][y]) {
				ans = dist[z][x][y];
			}
			return;
		}

		const int dz[] = { 0, 0, 0, 0, -1, 1 };
		const int dx[] = { 0, 0, 1, -1, 0, 0 };
		const int dy[] = { 1, -1, 0, 0, 0, 0 };


		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + dz[k];
			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || nz < 0 || nz >= MAX) continue;
			if (maze[nz][nx][ny] == 0 || dist[nz][nx][ny] != -1) continue;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
			qu.push({ nx , ny , nz });
		}
	}
}

int main() {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> arr[0][k][i][j];
			}
		}
	}
	rotate();
	int pan[5] = { 0, 1, 2, 3, 4 };
	do {
		for (int temp = 0; temp < 1024; temp++) {
			int brute = temp;
			for (int i = 0; i < 5; i++) {
				int dir = brute % 4; // brute & 3
				brute /= 4;
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						maze[i][x][y] = arr[dir][pan[i]][x][y];
					}
				}
			}
			bfs();
		}
	} while (next_permutation(pan, pan + 5));

	if (ans == 9999) ans = -1;
	cout << ans << '\n';
	return 0;
}