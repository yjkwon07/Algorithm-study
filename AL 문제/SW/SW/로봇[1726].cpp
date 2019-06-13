#include <iostream>
#include <queue>
using namespace std;
/*
	�κ�
	https://www.acmicpc.net/problem/1726

	�κ��� ��� �������� ���� �������� �̵��ϱ� ���� �ʿ��� �ּ� ��� Ƚ���� ���ϴ� ������. 
	BFS�� ���� �ִ� �Ÿ��� ���ϴ� �����ε�, ���� ��ȯ ��ɰ� �̵� ����� ���еǾ� �־ ��ٷӴ�.

	�̵� ����� ���� ������, �״����� ���� ��ȯ ����� ������ �帧���� ¥�� �Ѵ�.
	
	Queue���� 3���� ������ �־�� �Ѵ�. 
	�� ������ 'x��ǥ, y��ǥ, ���� ����'�̴�.
	
	�湮 ���θ� Ȯ���ϰ�, ��� Ƚ���� ������ �迭 'dist'�� 3���� �迭�� �����Ѵ�. 
	�ε����� ť�� ���� ������ ����.
	
	�̵� ����� 1, 2, 3 �Ÿ��� �̵��� �� �����Ƿ�, 1ĭ �̵����� 3ĭ �̵� ������ �����Ѵ�.
	�̵��� �� ���� �տ� ���� �ִٸ� ��ٷ� for ���� break �Ѵ�. 
	ª�� �Ÿ��� �� ����, �� �� �Ÿ��� ������ �� ���� �����̴�.
	���� �湮 üũ�� �ϰ�, �湮���� ���� ���̶�� ť�� ���� ��ǥ�� ���� ������ �ִ´�.
	�̵� ��� ���� ��ǥ�� �����ϰ�, ������ �����Ѵ�.

	�״����� ���� ��ȯ ����̴�. ������ ��, ��, ��, �� �����̴�. 
	�Ʒ� �ڵ忡���� ��(0), ��(1), ��(2), ��(3)���� �ε����� �Ű��.
	������ 4�� �����鼭, ���� ����� ���� ������ ���ٸ� ��ŵ �Ѵ�.
	
	���� ���� ��ȯ�� �ϴµ�, ���� 180�� ȸ���̶�� ����� 2�� ���� ���̰�, 90�� ȸ���̶�� ����� 1�� ���� ���̴�.
	180�� ȸ���� ��(0)�꼭(1), ��(2)���(3)�� ��츸 �����Ƿ�, �̴� (�������+��������)%4 == 1�� Ȯ���� �� �ִ�. 
	1�̶�� 180�� ȸ���̰�, 1�� �ƴϸ� 90�� ȸ���̴�.
	
	���� ��ȯ �� �湮 üũ�� �ϰ�, �湮���� ���� ���̶�� ������Ʈ�Ѵ�.
	���������� ������ ������ �̸� �ݺ��Ѵ�.
*/

#define MAX 110
int map[MAX][MAX];
int dist[MAX][MAX][4];
int n, m;

struct  MOVE
{
	int x, y, dir;
};

int cx, cy, cdir;
int fx, fy, fdir;

const int dx[] = {0, 0, 1, -1 };
const int dy[] = {1, -1, 0, 0 };

void bfs() {
queue<MOVE> qu;
	qu.push({ cx- 1, cy- 1 , cdir -1});
	
	while (!qu.empty())
	{
		int x = qu.front().x, y = qu.front().y, dir = qu.front().dir;
		qu.pop();

		if (x == fx - 1 && y == fy - 1 &&  dir == fdir -1) {
			cout << dist[x][y][dir] << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;  // Same direction.
			int k = (i + dir) % 4 == 1 ? 2 : 1;  // Check rotation. 180 degree (+2), 90 degree (+1)
			if (dist[x][y][i]) continue;   // Already visited.
			qu.push({ x, y, i });
			dist[x][y][i] = dist[x][y][dir] + k;
		}

		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
			if (map[nx][ny]) break;           // Cannot pass the wall.
			if (dist[nx][ny][dir]) continue;  // Already visited.
			qu.push({ nx, ny, dir });
			dist[nx][ny][dir] = dist[x][y][dir] + 1;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cin >> cx >> cy >> cdir;
	cin >> fx >> fy >> fdir;

	bfs();

	return 0;
}