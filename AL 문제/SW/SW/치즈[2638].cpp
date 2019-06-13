#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	치즈
	https://www.acmicpc.net/problem/2638

	0 ,0 start - > 가장 자리에 치즈를 배치 시킨다 했으므로
	while 무한 루프로 bfs() 돌리기
	check -> memest
	melt -> 3 over - > 0 -> ans++;
	else if melt -> 2 -> map을 다시 1로
*/

struct CHEZZE {
	int i, j;
};

#define MAX 100
queue<CHEZZE> qu;
int map[MAX][MAX];
bool check[MAX][MAX];
int n, m, ans;
const int dx[] = { 0, 0 , 1, -1 };
const int dy[] = { 1, -1, 0,  0 };

void bfs() {
	memset(check, false, sizeof(check));
	qu = queue<CHEZZE>();
	qu.push({ 0,0 });
	check[0][0] = true;

	while (!qu.empty()) {
		int x, y;
		CHEZZE chezze = qu.front();
		qu.pop();
		x = chezze.i;
		y = chezze.j;

		for (int k = 0; k < 4; k++) {
			int nx, ny;
			nx = x + dx[k];
			ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny]) continue;
			if (map[nx][ny] >= 1) {
				map[nx][ny]++;
				continue;
			}
			qu.push({ nx, ny });
			check[nx][ny] = true;
		}
	}
	return;
}

bool melt() {
	bool melted = false;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (map[i][j] >= 3) {
				map[i][j] = 0;
				melted = true;
			}
			else if (map[i][j] == 2) map[i][j] = 1;
		}
	}
	return melted;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		bfs();
		if (melt()) ans++;
		else break;
	}
	cout << ans << '\n';
	return 0;

}