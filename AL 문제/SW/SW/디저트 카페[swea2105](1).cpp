#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
/*
	디저트 카페
*/
#define MAX 20
#define DESERT_MAX 101
int arr[MAX][MAX];
bool checked[DESERT_MAX];
int ans = -1, N;
const int dx[] = { 1,1,-1,-1 };
const int dy[] = { -1,1,1,-1 };
int sx, sy;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(checked, false, sizeof(checked));
	ans = -1;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int x, int y, int dir, int cnt) {
	if (x == sx && y == sy && dir == 3) {
		ans = max(ans, cnt);
		return;
	}

	int nd, nx, ny;
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			nd = dir;
			nx = x + dx[nd];
			ny = y + dy[nd];
		}

		else {
			nd = dir + 1;
			nx = x + dx[nd];
			ny = y + dy[nd];
			if (nd > 3) break;
		}

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (!checked[arr[nx][ny]]) {
			checked[arr[nx][ny]] = true;
			dfs(nx, ny, nd, cnt + 1);
			checked[arr[nx][ny]] = false;
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sx = i;
			sy = j;
			dfs(i, j, 0, 0);
		}
	}
}

int main() {
	int test_Case;
	cin >> test_Case;
	int t = 1;
	while (test_Case--) {
		init();
		input();
		solve();
		cout << "#" << t++ << " " << ans << '\n';
	}
	return 0;
}