#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
/*
PuyoPuyo
https://www.acmicpc.net/problem/11559
*/

int arr[12][6];
bool checked[12][6];
struct MOVE {
	int x, y;
};
const int dx[] = { 0, 0 , 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

bool bfs(int color, int i, int j) {

	queue<MOVE> qu;
	qu.push({ i, j });
	checked[i][j] = true;
	int cnt = 1;

	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (checked[nx][ny])continue;
			if (arr[nx][ny] != color) continue;
			checked[nx][ny] = true;
			qu.push({ nx, ny });
			cnt++;
		}
	}
	if (cnt >= 4) {
		return true;
	}
	else return false;
}

void clear(int color, int i, int j) {
	queue<MOVE> qu;
	qu.push({ i, j });
	arr[i][j] = 0;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (arr[nx][ny] != color) continue;
			arr[nx][ny] = 0;
			qu.push({ nx, ny });
		}
	}
}

bool line_clear() {
	bool ok = false;
	for (int y = 0; y < 6; y++) {
		for (int x = 10; x >= 0; x--) {
			if (arr[x][y] == 0 && arr[x + 1][y] == 0) continue;
			if (arr[x + 1][y] == 0) {
				arr[x + 1][y] = arr[x][y];
				arr[x][y] = 0;
				ok = true;
			}
		}
	}
	return ok;
}

int main() {
	for (int x = 0; x < 12; x++) {
		for (int y = 0; y < 6; y++) {
			char temp;
			cin >> temp;
			if (temp == '.') {
				arr[x][y] = 0;
			}
			else if (temp == 'R') {
				arr[x][y] = 1;
			}
			else if (temp == 'G') {
				arr[x][y] = 2;
			}
			else if (temp == 'B') {
				arr[x][y] = 3;
			}
			else if (temp == 'P') {
				arr[x][y] = 4;
			}
			else if (temp == 'Y') {
				arr[x][y] = 5;
			}
		}
	}

	int cnt = 0;
	while (true) {
		memset(checked, false, sizeof(checked));
		bool ok = false;

		for (int y = 0; y < 6; y++) {
			for (int x = 11; x >= 0; x--) {
				if (arr[x][y] != 0) {
					bool ck = bfs(arr[x][y], x, y);
					if (ck) {
						ok = true;
						clear(arr[x][y], x, y);
					}
				}
			}
		}

		if (ok) {
			while (true) {
				bool line = false;
				line = line_clear();
				if (!line) break;
			}
			cnt++;
		}
		else break;
	}

	cout << cnt << '\n';
	return 0;
}