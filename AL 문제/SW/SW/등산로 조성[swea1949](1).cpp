#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
	등산로 조성
*/
#define MAX_N 8
int arr[MAX_N][MAX_N];
bool checked[MAX_N][MAX_N];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0 , 0 };
int ans, N, K;
struct MOVE {
	int x, y;
};
vector<MOVE> v;

void init() {
	memset(checked, false, sizeof(checked));
	memset(arr, 0, sizeof(arr));
	v = vector<MOVE>();
	ans = 0;
}

void input() {
	cin >> N >> K;
	int df = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (df < arr[i][j]) {
				df = arr[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (df == arr[i][j]) v.push_back({ i , j });
		}
	}
}

void dfs(int cnt, int x, int y, int only) {

	int count = 0;
	for (int k = 0; k< 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (arr[nx][ny] < arr[x][y]) {
			if (!checked[nx][ny]) {
				checked[nx][ny] = true;
				dfs(cnt + 1, nx, ny, only);
				checked[nx][ny] = false;
				count++;
			}
		}

		else {
			if (only == 0) {
				if (arr[nx][ny] - K < arr[x][y]) {
					if (!checked[nx][ny]) {
						checked[nx][ny] = true;
						only = 1;
						int temp = arr[nx][ny];
						arr[nx][ny] = (arr[x][y] - 1);
						dfs(cnt + 1, nx, ny, only);
						arr[nx][ny] = temp;
						only = 0;
						checked[nx][ny] = false;
						count++;
					}
				}
			}
		}
	}

	if (count == 0) {
		ans = max(ans, cnt);
		return;
	}
}

int main() {
	int test_Case;
	cin >> test_Case;
	int t = 1;
	while (test_Case--) {
		init();
		input();
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			checked[x][y] = true;
			dfs(1, x, y, 0);
			checked[x][y] = false;
		}
		cout << "#" << t++ << " " << ans << '\n';
	}
	return 0;
}