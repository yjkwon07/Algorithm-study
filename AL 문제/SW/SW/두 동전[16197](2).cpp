#include<iostream>
#include<vector>
using namespace std;
/*
	두 동전
	https://www.acmicpc.net/problem/16197
	DFS 32ms (permutation)을 하기 때문
*/
int n, m, ans;
char map[20][20];
vector<pair<int, int > > coin;
int dx[] = { 0 ,0 , 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Min(int a, int b) {
	if (a < b) return a;
	return b;
}

void Input() {
	ans = 999999999;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') coin.push_back(make_pair(i, j));
		}
	}
}

bool Range_Over(int a, int b) {
	if (a < 0 || b < 0 || a >= n || b >= m) return true;
	return false;
}

void Move(int x, int y, int xx, int yy, int cnt, int dir) {
	if (ans < cnt) return;
	if (cnt > 10) {
		/*ans = Min(ans, cnt);*/
		return;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int nxx = xx + dx[dir];
	int nyy = yy + dy[dir];

	if (Range_Over(nx, ny) && Range_Over(nxx, nyy)) return;
	else if (Range_Over(nx, ny)|| Range_Over(nxx, nyy)) {
		ans = Min(ans, cnt);
		return;
	}

	if (map[nx][ny] == '#') {
		nx = x;
		ny = y;
	}

	if (map[nxx][nyy] == '#') {
		nxx = xx;
		nyy = yy;
	}
	
	for (int i = 0; i < 4; i++) {
		Move(nx, ny, nxx, nyy, cnt + 1, i);
	}
}

void Solution() {
	for (int i = 0; i < 4; i++) {
		int x = coin[0].first;
		int y = coin[0].second;
		int xx = coin[1].first;
		int yy = coin[1].second;

		Move(x, y, xx, yy, 1, i);
	}

}

void solve() {
	Input();
	Solution();
	if (ans > 10) ans = -1;
	cout << ans << '\n';
}
int main() {
	solve();

	return 0;
}