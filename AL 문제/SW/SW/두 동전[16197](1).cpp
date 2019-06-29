#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
/*
	두 동전
	https://www.acmicpc.net/problem/16197

	BFS 탐색을 통해 두 동전을 보드에서 떨어뜨리는 최단 거리를 구하면 된다. 
	동전 두 개가 동시에 움직이므로, 방문 여부를 확인할 배열을 4차원으로 설정하는 것이 좋다. 
	'구슬 탈출'과 비슷한 문제다.

	방문 여부를 확인하고 거리를 저장할 배열 dist를 4차원으로 선언한다. (동전1 X좌표, 동전1 Y좌표, 동전2 X좌표, 동전2 Y좌표)
	보드를 입력받을 때 가장자리를 0으로 비워두고, 입력받는다. 즉, N*M 사이즈를 (N+2)*(M+2) 사이즈로 확장한다.
	동전 두 개 중 하나가, 가장자리(인덱스 0, N+1 또는 0, M+1)인 경우 BFS 탐색을 중지하고 거리를 출력한다.
	동전이 둘 다 가장자리로 갔다면, 둘 다 떨어뜨릴 수 없으므로 무시한다.
	동전이 벽(#)에 부딪혔을 경우, 동전 둘 다 부딪쳤다면 이동이 불가능하다.
	동전이 하나만 벽에 부딪혔을 경우, 하나는 그대로 움직이고 하나는 이동하기 전으로 되돌려 놓는다.
	이동 거리가 10을 넘는다면, 버튼을 10번 넘게 누른 것이므로 BFS 탐색을 중지한다.

*/
#define MAX 50
char arr[MAX][MAX];
int dist[MAX][MAX][MAX][MAX];
int r, c;
struct COIN
{
	int x1, y1, x2, y2;
};
queue<COIN> qu;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0 ,0 };

bool _conin_out(int x, int y) {
	if (x < 1 || x > r || y < 1 || y > c) {
		return true;
	}
	else return false;
}

bool _coin_wall(int x, int y) {
	if (arr[x][y] == '#') return true;
	else return false;
}

void bfs() {
	while (!qu.empty()) {
		int x1 = qu.front().x1;
		int y1 = qu.front().y1;
		int x2 = qu.front().x2;
		int y2 = qu.front().y2;
		qu.pop();

		if (dist[x1][y1][x2][y2] > 10) break;

		// 둘 중 한 개만 out return -> count over? 
		if (_conin_out(x2, y2) ^ _conin_out(x1, y1)) {
			cout << dist[x1][y1][x2][y2] << '\n';
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx1 = x1 + dx[k];
			int ny1 = y1 + dy[k];
			int nx2 = x2 + dx[k];
			int ny2 = y2 + dy[k];

			// 둘 다 out -> continue
			if (_conin_out(nx2, ny2) && _conin_out(nx1, ny1)) {
				continue;
			}

			// 둘 다 check -> is it wall? -> continue
			if (_coin_wall(nx1, ny1) && _coin_wall(nx2, ny2)) {
				continue;
			}

			if (_coin_wall(nx1, ny1)) nx1 = x1, ny1 = y1;
			else if (_coin_wall(nx2, ny2)) nx2 = x2, ny2 = y2;

			// dist check -> continue
			if (dist[nx1][ny1][nx2][ny2]) continue;

			dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
			qu.push({ nx1, ny1, nx2, ny2 });
		}
	}

	cout << -1 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//memset(dist, -1, sizeof(dist));

	cin >> r >> c;
	int s[4];
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				s[cnt++] = i;
				s[cnt++] = j;
			}
		}
	}

	qu.push({ s[0], s[1], s[2], s[3] });
	dist[s[0]][s[1]][s[2]][s[3]] = 0;
	bfs();
	return 0;
}