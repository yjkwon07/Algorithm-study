#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
/*
	인구 이동
*/
#define MAX 50
#define LR 100
int arr[MAX][MAX];
int checked[MAX][MAX];
struct MOVE {
	int x, y;
};
int L, R, N;
int ans;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(checked, -1, sizeof(checked));
	L = 0;
	R = 0;
	N = 0;
	ans = 0;
}

void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << checked[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool checkPeople(int x, int y, int c) {
	const int dx[] = { 0 , 0, 1, -1 };
	const int dy[] = { 1, -1, 0 ,0 };
	int cnt = 1;
	int sum = arr[x][y];

	queue <MOVE> q;
	vector<MOVE> country;
	country.push_back({ x, y });
	q.push({ x , y });
	checked[x][y] = c;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (checked[nx][ny] != -1) continue;
			int cha = arr[cx][cy] - arr[nx][ny];
			if (cha < 0) cha = -cha;
			if (L <= cha && cha <= R) {
				checked[nx][ny] = c;
				cnt++;
				sum += arr[nx][ny];
				q.push({ nx ,ny });
				country.push_back({ nx , ny });
			}
		}
	}

	if (cnt == 1) {
		return false;
	}
	else { 
		int result = sum / cnt;
		for (int i = 0; i < country.size(); i++) {
			int cx = country[i].x;
			int cy = country[i].y;
			arr[cx][cy] = result;
		}
		return true;
	}
}

void solve() {
	int count = 0;
	while (true) {
		bool flag = false;
		int cnt = 0;
		memset(checked, -1, sizeof(checked));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (checked[i][j] == -1) {
					if (checkPeople(i, j, cnt++)) {
						flag = true;
					}
				}
			}
		}
		if (flag == false) break;
		else count++;
	}
	ans = count;
}

int main() {
	init();
	input();
	solve();
	cout << ans << '\n';
	return 0;
}