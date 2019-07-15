#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
	치킨 배달
	https://www.acmicpc.net/problem/15686
*/
#define MAX 50
int arr[MAX][MAX];
bool checked[MAX][MAX];
int N, M, ans = 9999;
struct MOVE {
	int x, y;
};
vector<MOVE> v;
vector<MOVE> ho;

int cal() {
	int result = 0;
	for (int i = 0; i < ho.size(); i++) {
		int cnt = 9999;
		int r1 = ho[i].x;
		int c1 = ho[i].y;
		for (int j = 0; j < v.size(); j++) {
			int r2 = v[j].x;
			int c2 = v[j].y;

			if (checked[r2][c2]) {
				int result = abs(r1 - r2) + abs(c1 - c2);
				cnt = min(cnt, result);
			}
		}
		result += cnt;
	}
	return result;

}

void dfs(int cnt, int index) {
	if (cnt == M) {
		ans = min(ans, cal());
		return;
	}

	for (int i = index; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		if (!checked[x][y]) {
			checked[x][y] = true;
			dfs(cnt + 1, i + 1);
			checked[x][y] = false;
		}
	}
}

int main() {
	memset(checked, false, sizeof(checked));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i , j });
			}
			if (arr[i][j] == 1) {
				ho.push_back({ i , j });
			}
		}
	}

	dfs(0, 0);
	cout << ans << '\n';

}