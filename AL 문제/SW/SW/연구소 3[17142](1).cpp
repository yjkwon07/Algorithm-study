#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/*
	연구소3
	https://www.acmicpc.net/problem/17142

	O(n)을 요구 
	dfs + bfs 모두 구하는 문제 
	함수 중복성 피하기 !!!
*/
#define MAX 10

//bfs
int arr[MAX * 5][MAX *5];
int checked[MAX * 5][MAX * 5];
struct MOVE {
	int x, y;
};
queue<MOVE> qu;

//dfs
MOVE dfs_total[MAX];
int dfs_number[MAX];
bool dfs_checked[MAX];

int ans = 9999;
int n, m, total, k;

/*
시간 초과
O(n^2) 
int _check() {
	// arr => 2 를 checked[][] = -2로 작업(비활성화)
	int number = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 벽 || 비활성화
			if (arr[i][j] == 1 || checked[i][j] == -2) continue;
			// 빈칸에서 값이 없으면 
			if (arr[i][j] == 0 && checked[i][j] == -1) return 9999;
			// 빈칸에서 값이 있으면 
			if (checked[i][j] != 0) {
				if (number < checked[i][j]) number = checked[i][j];
			}
			// 이전 비교보다 크면
			if (ans <= number) return 9999;
		}
	}
	return number;
}
*/

int bfs() {
	const int dx[] = { 0, 0, 1, -1 };
	const int dy[] = { 1, -1, 0, 0 };
	int number = 0;
	int time = 0;

	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] != 1 && checked[nx][ny] == -1) {
				checked[nx][ny] = checked[x][y] + 1;
				if (arr[nx][ny] == 0) {
					number = checked[nx][ny];
					time++;
				}
				qu.push({ nx, ny });
			}
		}
	}
	if (time == k) return number;
	else return 9999;
}

void dfs(int ibx, int cnt) {
	if (cnt == m) {
		memset(checked, -1, sizeof(checked));
		for (int i = 0; i < m; i++) {
			int x = dfs_total[dfs_number[i]].x;
			int y = dfs_total[dfs_number[i]].y;
			qu.push({ x , y });
			checked[x][y] = 0;
		}
		ans = min(ans, bfs());
		return;
	}

	for (int i = ibx; i < total; i++) {
		if (!dfs_checked[i]) {
			dfs_checked[i] = true;
			dfs_number[cnt] = i;
			dfs(i + 1, cnt + 1);
			dfs_number[cnt] = -1;
			dfs_checked[i] = false;
		}
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				dfs_total[total++] = { i  , j };
			}
			if (arr[i][j] == 0) k += 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	dfs(0, 0);
	if (ans == 9999) ans = -1;
	cout << ans << '\n';
	return 0;
}