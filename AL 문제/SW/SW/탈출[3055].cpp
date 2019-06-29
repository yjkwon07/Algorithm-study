#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
/*	
	탈출
	https://www.acmicpc.net/problem/3055

	BFS를 통해 고슴도치가 동굴까지 이동하는 최단 거리를 구하는 문제다. 
	1분마다 물은 상하좌우로 1칸씩 번지고, 고슴도치도 1칸씩 움직인다. 
	고슴도치는 물로 이동할 수 없고, 다음 시간에 물이 차는 곳으로도 갈 수 없다. 
	때문에 물을 먼저 Queue에 넣고, 그다음 고슴도치를 Queue에 넣어 BFS를 돌리면 된다.

	Queue에 고슴도치의 위치와 물의 위치가 들어가므로, 물과 고슴도치를 구별할 flag를 만든다.
	map struct의 변수 s가 1인 경우 고슴도치이며, 0인 경우 물이다.
	입력받을 때, 물(*)은 곧바로 Queue에 넣고, 고슴도치(S)는 위치를 기억해둔다.
	입력이 끝난 후, 고슴도치의 위치를 Queue에 넣는다.
	고슴도치와 물은 돌(X)로 이동할 수 없고, 비어있는 칸(.)으로 이동한다.
	dist 배열을 통해 이동거리를 저장하고, 값이 1 이상인 경우 방문한 장소로 기억한다.
	다음 이동에서 동굴(D)을 만나면, s 값을 통해 고슴도치인지 물인지 확인한다.
	물인 경우 무시하고, 고슴도치라면 결과를 출력하고 종료한다.
	Queue가 완전히 빌 때까지 결과를 찾지 못했으면, 동굴에 도착하지 못한 것이므로, KAKTUS를 출력하고 종료한다.
*/
#define MAX 50
char arr[MAX][MAX];
int dist[MAX][MAX][2];
int r, c;
struct MOVE {
	int x, y;
};
queue<MOVE> qu;
MOVE biber[2];
MOVE water;
const int dx[] = { 0 , 0 , 1, -1 };
const int dy[] = { 1, -1, 0 , 0 };

void print(int arr[MAX][MAX][2], int k) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j][k] << ' ';
		}
		cout << '\n';
	}
}

void _watergo() {

	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist[nx][ny][0] != -1) continue;
			if (arr[nx][ny] == 'X') continue;
			if (arr[nx][ny] == 'D') continue;
			dist[nx][ny][0] = dist[x][y][0] + 1;
			qu.push({ nx , ny });
		}
	}
	// print(dist , 0);
}

void _bibergo() {
	qu = queue<MOVE>();
	qu.push(biber[1]);
	dist[biber[1].x][biber[1].y][1] = 0;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist[nx][ny][1] != -1) continue;
			if (arr[nx][ny] == 'X') continue;
			if (dist[nx][ny][0] > dist[x][y][1] + 1 || dist[nx][ny][0] == -1) {
				dist[nx][ny][1] = dist[x][y][1] + 1;
				qu.push({ nx, ny });
			}
		}
	}

	// print(dist, 1);
	if (dist[biber[0].x][biber[0].y][1] == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << dist[biber[0].x][biber[0].y][1] << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dist, -1, sizeof(dist));
	memset(arr, ' ', sizeof(arr));

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') {
				biber[0] = { i , j };
			}
			else if (arr[i][j] == 'S') {
				biber[1] = { i , j };
			}
			else if (arr[i][j] == '*') {
				qu.push({ i , j });
				dist[i][j][0] = 0;
			}
		}
	}

	_watergo();
	_bibergo();
	return 0;
}