#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	* ������ ��Ű� ����(BFS ����)
	
	�ſＳġ
	https://www.acmicpc.net/problem/2151

	������ �ٸ� ������ ������ �����ϱ� ���� �ʿ��� �ſ��� �ּ� ������ ���ϴ� ������. 
	���� �ſ￡���� ���̰�, �ſ��� 45�� ������ ��ġ�� �� �ִ�. 
	�ſ��� ������ ��ġ�ؼ� ������ ������ ���� �����ؾ� �Ѵ�.

	��('#')�� �׻� 2���� �־����Ƿ�, �ϳ��� ���� ����������, �ٸ� �ϳ��� ���� ���������� �д�.
	BFS Ž���� �ϸ鼭 ���� �̵� ��ǥ�� �� �� �ִ� ������ Ȯ���Ѵ�.
	�湮 üũ�� �ſ� ��ġ Ƚ���� ������ �迭 dist�� 3�������� �����Ѵ�.
	dist�� �ε����� [X ��ǥ] [Y��ǥ] [�̵� ����] �̴�.
	���� ���� �̵� ��ǥ�� ���� ���̰ų� ��('*')�̶��, �̵��� �� ����.
	���� �̵� ��ǥ�� �� ����('.')�̶��, ��� �̵��Ѵ�.
	while �ݺ����� ���� ���� �̵��� ������ ��ġ���, ���� �������� ��� �̵��Ѵ�.
	�̵��ϴٰ� �ſ��� ���� �� �ִ� ���('!')�� �����ϸ�, ���� �̵� ��ǥ�� 3������ ť�� �ִ´�.
	ù ��°, ���� �̵� ����� ���� ������ ��ǥ�� �ִ´�. (�ſ� ��ġ�� ���� �ʴ´�.)
	�� ��°, ������ +90���� ���� ��ǥ�� �ִ´�. (�ſ��� ��ġ�Ѵ�.)
	�� ��°, ������ -90���� ���� ��ǥ�� �ִ´�. (�ſ��� ��ġ�Ѵ�.)
	�� ������ ���������� ������ ������ �ݺ��Ѵ�.

	�ſ��� ���� ���� �̵��� �Ʒ��� ���� ��Ÿ�� �� �ִ�.
	�켱 ������ [��0  ��1  ��2  ��3 ] ���� �д�.
	����(0) ������ ����(2)�̳� ������(3)���� ���δ�. [ 0 �� 2 , 0 �� 3 ]
	�Ʒ���(1) ������ ����(2)�̳� ������(3)���� ���δ�. [ 1 �� 2 , 1 �� 3 ]
	����(2) ������ ����(0)�̳� �Ʒ���(1)���� ���δ�. [ 2 �� 0 , 2 �� 1 ]
	������(3) ������ ����(0)�̳� �Ʒ���(1)���� ���δ�. [ 3 �� 0 , 3 �� 1 ]
*/
#define MAX 50
char arr[MAX][MAX];
int n;
int dist[MAX][MAX][4]; // ��ǥ , dir
const int dx[] = { -1 , 1 , 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct MOVE {
	int x, y, z;
};
int ex, ey;
queue<MOVE> qu;

bool out(int nx, int ny, int z) {
	if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
	if (arr[nx][ny] == '*') return false;
	return true;
}

void bfs() {
	while (!qu.empty())
	{
		int x = qu.front().x;
		int y = qu.front().y;
		int z = qu.front().z;
		qu.pop();

		// find
		if (x == ex && y == ey) {
			printf("%d\n", dist[x][y][z]);
			return;
		}

		// search		
		int nx = x + dx[z];
		int ny = y + dy[z];

		while (out(nx, ny, z) && arr[nx][ny] == '.') {
			nx += dx[z];
			ny += dy[z];
		}

		if (out(nx, ny, z) && arr[nx][ny] == '!') {
			dist[nx][ny][z] = dist[x][y][z];
			qu.push({ nx, ny , z });

			int k = z < 2 ? 2 : 0;
			for (int i = k; i<k + 2; i++) {
				if (dist[nx][ny][i] == -1) {
					dist[nx][ny][i] = dist[x][y][z] + 1;
					qu.push({ nx, ny, i });
				}
			}
		}
	}
}

void print() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j <n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	scanf("%d", &n);
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == '#') {
				if (qu.empty()) {
					for (int k = 0; k<4; k++) {
						qu.push({ i, j, k });
						dist[i][j][k] = 0;
					}
				}
				else {
					ex = i, ey = j;
				}
				arr[i][j] = '!';
			}
		}
	}

	// print();
	bfs();
	return 0;
}