#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
/*
	�� ����
	https://www.acmicpc.net/problem/16197

	BFS Ž���� ���� �� ������ ���忡�� ����߸��� �ִ� �Ÿ��� ���ϸ� �ȴ�. 
	���� �� ���� ���ÿ� �����̹Ƿ�, �湮 ���θ� Ȯ���� �迭�� 4�������� �����ϴ� ���� ����. 
	'���� Ż��'�� ����� ������.

	�湮 ���θ� Ȯ���ϰ� �Ÿ��� ������ �迭 dist�� 4�������� �����Ѵ�. (����1 X��ǥ, ����1 Y��ǥ, ����2 X��ǥ, ����2 Y��ǥ)
	���带 �Է¹��� �� �����ڸ��� 0���� ����ΰ�, �Է¹޴´�. ��, N*M ����� (N+2)*(M+2) ������� Ȯ���Ѵ�.
	���� �� �� �� �ϳ���, �����ڸ�(�ε��� 0, N+1 �Ǵ� 0, M+1)�� ��� BFS Ž���� �����ϰ� �Ÿ��� ����Ѵ�.
	������ �� �� �����ڸ��� ���ٸ�, �� �� ����߸� �� �����Ƿ� �����Ѵ�.
	������ ��(#)�� �ε����� ���, ���� �� �� �ε��ƴٸ� �̵��� �Ұ����ϴ�.
	������ �ϳ��� ���� �ε����� ���, �ϳ��� �״�� �����̰� �ϳ��� �̵��ϱ� ������ �ǵ��� ���´�.
	�̵� �Ÿ��� 10�� �Ѵ´ٸ�, ��ư�� 10�� �Ѱ� ���� ���̹Ƿ� BFS Ž���� �����Ѵ�.

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

		// �� �� �� ���� out return -> count over? 
		if (_conin_out(x2, y2) ^ _conin_out(x1, y1)) {
			cout << dist[x1][y1][x2][y2] << '\n';
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx1 = x1 + dx[k];
			int ny1 = y1 + dy[k];
			int nx2 = x2 + dx[k];
			int ny2 = y2 + dy[k];

			// �� �� out -> continue
			if (_conin_out(nx2, ny2) && _conin_out(nx1, ny1)) {
				continue;
			}

			// �� �� check -> is it wall? -> continue
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