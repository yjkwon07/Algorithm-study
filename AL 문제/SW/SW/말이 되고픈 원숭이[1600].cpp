#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/*
말이 되고픈 원숭이
https://www.acmicpc.net/problem/1600
1. Horse_cnt (감소할 수 있는 상황별 구별하기)
[X][Y][Horse_Cnt]
2. 체스는 옮겨지는 과정에서 장애물은 크게 상관이 없다. (장기랑 다름)
3. x, y 인지 부족
*/

#define MAX 200
#define HORSE 31
int map[MAX][MAX];
int dist[MAX][MAX][HORSE];
int k, x, y, ans = -1;
const int dx[] = { 0, 0, 1,-1 ,2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, -1, 0 , 0,1, 2, 2, 1, -1, -2, -2, -1 };

struct MOVE {
	int x, y, cnt;
};
queue<MOVE> qu;

void bfs() {

	qu.push({ 0 , 0 , 0 });
	dist[0][0][0] = 0;
	while (!qu.empty())
	{
		MOVE move = qu.front(); qu.pop();
		int cx = move.x, cy = move.y;
		int cz = move.cnt;
		if (cx == x - 1 && cy == y - 1) {
			ans = dist[cx][cy][cz];
			return;
		}
		// Maximum count(Horse)
		int j = cz == k ? 4 : 12;

		for (int i = 0; i < j; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = i < 4 ? cz : cz + 1;
			if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (dist[nx][ny][nz] || map[nx][ny]) continue;
			qu.push({ nx , ny , nz });
			dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
		}
	}

	ans = -1; 
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	cin >> y >> x;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	cout << ans << '\n';
	return 0;
}