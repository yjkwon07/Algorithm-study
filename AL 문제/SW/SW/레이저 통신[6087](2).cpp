#include<iostream>
#include<tuple>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
/*
	레이저 통신
	https://www.acmicpc.net/problem/6087


*/
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int x1[2], y1[2];
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'C') {
				x1[c] = i;
				y1[c++] = j;
			}
		}
	}
	vector<vector<int>> dist(m, vector<int>(n, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(x1[0], y1[0]));
	dist[x1[0]][y1[0]] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (a[nx][ny] == '*') break;
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
	cout << dist[x1[1]][y1[1]] - 1 << '\n';
	cin >> n;
	return 0;
}