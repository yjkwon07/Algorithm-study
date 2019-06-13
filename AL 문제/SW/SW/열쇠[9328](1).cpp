#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	����
	https://www.acmicpc.net/problem/9328
	ť�� �� 2���� �����̴�. �̵� ��ġ�� ��Ÿ�� Position queue��,
	���� ��ġ�� ��Ÿ�� Door queue�̴�.
	Door queue�� ����� ���������� 26���̴�.
	
	����� (0, 0)����, ���� �ۿ��� �����Ѵ�.
	���� �̵��ϸ鼭 ������ ����ų�, ��(*)�� ������ �����Ѵ�.
	���� �̵��ϸ鼭 ��(A~Z)�� ������, �ش� ���� ��ġ�� Door queue�� ���� �ִ´�.
	���� �̵��ϸ鼭 ����(a~z)�� ������, �ش� ���踦 true�� �Ѵ�. 
	�׸��� Door queue�� �ش� ���ڿ� ���� ��� ���� pop�Ͽ� Position queue�� ���� �ִ´�.
	���� �̵��ϸ鼭 ����($)�� ������, �̸� ī��Ʈ�Ѵ�.
	�׽�Ʈ ���̽��� ���� �� �����Ƿ�, ������ �ʱ�ȭ�� ���� ���ƾ� �Ѵ�.


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