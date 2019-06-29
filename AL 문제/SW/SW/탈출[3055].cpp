#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
/*	
	Ż��
	https://www.acmicpc.net/problem/3055

	BFS�� ���� ����ġ�� �������� �̵��ϴ� �ִ� �Ÿ��� ���ϴ� ������. 
	1�и��� ���� �����¿�� 1ĭ�� ������, ����ġ�� 1ĭ�� �����δ�. 
	����ġ�� ���� �̵��� �� ����, ���� �ð��� ���� ���� �����ε� �� �� ����. 
	������ ���� ���� Queue�� �ְ�, �״��� ����ġ�� Queue�� �־� BFS�� ������ �ȴ�.

	Queue�� ����ġ�� ��ġ�� ���� ��ġ�� ���Ƿ�, ���� ����ġ�� ������ flag�� �����.
	map struct�� ���� s�� 1�� ��� ����ġ�̸�, 0�� ��� ���̴�.
	�Է¹��� ��, ��(*)�� ��ٷ� Queue�� �ְ�, ����ġ(S)�� ��ġ�� ����صд�.
	�Է��� ���� ��, ����ġ�� ��ġ�� Queue�� �ִ´�.
	����ġ�� ���� ��(X)�� �̵��� �� ����, ����ִ� ĭ(.)���� �̵��Ѵ�.
	dist �迭�� ���� �̵��Ÿ��� �����ϰ�, ���� 1 �̻��� ��� �湮�� ��ҷ� ����Ѵ�.
	���� �̵����� ����(D)�� ������, s ���� ���� ����ġ���� ������ Ȯ���Ѵ�.
	���� ��� �����ϰ�, ����ġ��� ����� ����ϰ� �����Ѵ�.
	Queue�� ������ �� ������ ����� ã�� ��������, ������ �������� ���� ���̹Ƿ�, KAKTUS�� ����ϰ� �����Ѵ�.
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