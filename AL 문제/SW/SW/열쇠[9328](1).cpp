#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	열쇠
	https://www.acmicpc.net/problem/9328
	큐는 총 2가지 종류이다. 이동 위치를 나타낼 Position queue와,
	문의 위치를 나타낼 Door queue이다.
	Door queue는 열쇠와 마찬가지로 26개이다.
	
	출발은 (0, 0)으로, 빌딩 밖에서 시작한다.
	맵을 이동하면서 범위를 벗어나거나, 벽(*)을 만나면 무시한다.
	맵을 이동하면서 문(A~Z)을 만나면, 해당 문의 위치를 Door queue에 집어 넣는다.
	맵을 이동하면서 열쇠(a~z)를 만나면, 해당 열쇠를 true로 한다. 
	그리고 Door queue의 해당 문자에 대한 모든 값을 pop하여 Position queue에 집어 넣는다.
	맵을 이동하면서 문서($)를 만나면, 이를 카운트한다.
	테스트 케이스가 여러 번 있으므로, 데이터 초기화를 잊지 말아야 한다.


*/

#define MAX 110
struct MOVE
{
	int x, y;
};
bool keys[MAX];
char map[MAX][MAX];
bool checked[MAX][MAX];
int h, w, ans;
const int dx[] = { 0 , 0 ,1, -1 };
const int dy[] = { 1 ,-1, 0, 0 };

void printa() {
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {

			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void init() {
	memset(map, '.', sizeof(map));
	memset(keys, false, sizeof(keys));
	memset(checked, false, sizeof(checked));
	ans = 0;
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			char temp;
			scanf("%1s", &temp);
			if (temp != '.') map[i][j] = temp;
		}
	}

	// printa();

	char k[26];
	scanf("%s", k);
	for (int i = 0; i<(int)strlen(k); i++) {
		if (k[i] == '0') break;
		keys[k[i] - 'a'] = true;
	}
	return;
}

void bfs() {
	queue<MOVE> qu;
	queue<MOVE> door[MAX];

	qu.push({ 0,0 });
	checked[0][0] = true;

	while (!qu.empty()) {
		int x = qu.front().x, y = qu.front().y;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
			if (checked[nx][ny]) continue;
			if (map[nx][ny] == '*') continue;
			checked[nx][ny] = true;
			if (map[nx][ny] == '$') ans++;
			else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
				if (!keys[map[nx][ny] - 'A']) {
					door[map[nx][ny] - 'A'].push({ nx, ny });
					continue;
				}
			}
			else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
				keys[map[nx][ny] - 'a'] = true;
				while (!door[map[nx][ny] - 'a'].empty()) {
					int kx = door[map[nx][ny] - 'a'].front().x;
					int ky = door[map[nx][ny] - 'a'].front().y;
					door[map[nx][ny] - 'a'].pop();
					qu.push({ kx, ky });
				}
			}
			qu.push({ nx, ny });
		}
	}

}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		init();
		bfs();
		cout << ans << '\n';
	}
}