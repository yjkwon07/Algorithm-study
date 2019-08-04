#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
	사다리 조작
	https://www.acmicpc.net/problem/15684
	1656ms
*/
#define MAX 30
int arr[MAX][MAX];
int N, M, H, ans;

void init() {
	memset(arr, 0, sizeof(arr));
	ans = 9999;
}

void input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check() {
	//print();
	for (int i = 0; i < N; i++) {
		int col = i;
		for(int j = 0; j < H; j++) {
			if (arr[j][col]) {
				col++;
			}
			else if (arr[j][col - 1]) {
				col--;
			}
		}
		if (i != col) return false;
	}
	return true;
	
}

void dfs(int x, int y, int cnt) {
	if (cnt <= 3) {
		if (check()) {
			ans = min(ans, cnt);
			return;
		}
	}
	else return;

	for (int i = x; i < H; i++) {
		for (int j = y; j < N; j++) {
			if (!arr[i][j] && (!arr[i][j - 1] && !arr[i][j + 1])) {
				arr[i][j] = 1;
				dfs(i, j, cnt + 1);
				arr[i][j] = 0;
			}
		}
		y = 0;
	}

}

void solve() {
	dfs(0, 0, 0);
}

int main() {
	init();
	input();
	solve();
	if (ans == 9999) ans = -1;
	cout << ans << '\n';
	return 0;
}