#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
레이저 통신
https://www.acmicpc.net/problem/6087


*/
#define MAX 100
int r, c;
struct MOVE {
	int x, y;
};
MOVE start;
MOVE tends;
char arr[MAX][MAX];
int dist[MAX][MAX];

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void bfs() {
	queue<MOVE> qu;
	qu.push(start);
	dist[start.x][start.y] = 0;

	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();

		if (x == tends.x && y == tends.y) {
			cout << dist[x][y] - 1 << '\n';
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			while (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (arr[nx][ny] == '*') break;
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					qu.push({ nx, ny });
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> r;
	int count = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				if (count == 0) {
					start = { i , j };
					count++;
				}
				else if (count == 1) {
					tends = { i , j };
				}
			}
		}
	}
	memset(dist, -1, sizeof(dist));
	bfs();
	return 0;
}