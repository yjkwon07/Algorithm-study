#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<set>
using namespace std;
/*
	벽 부수고 이동하기4
	https://www.acmicpc.net/problem/16946

*/
#define MAX 1000
int arr[MAX][MAX];
bool checked[MAX][MAX];
int dist[MAX][MAX];
int result[MAX][MAX];
int n, m;
map<int, int > mp;

struct MOVE {
	int x, y;
};

queue<MOVE> qu;
const int dx[] = { 0, 0 , 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int bfs(int i, int j, int cnt) {
	qu.push({ i ,j });
	checked[i][j] = true;
	dist[i][j] = cnt;
	int count = 1;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1) continue;
			if (checked[nx][ny])continue;

			checked[nx][ny] = true;
			dist[nx][ny] = cnt;
			count++;
			qu.push({ nx, ny });
		}
	}
	return count;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] % 10;
		}
		cout << '\n';
	}
}

void print2() {
	for (int i = 1; i <= mp.size(); i++) {
		cout << mp[i] << '\n';
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &arr[i][j]);
		}
	}

	int cnt = 1;
	memset(dist, 0, sizeof(dist));
	memset(checked, false, sizeof(checked));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) continue;
			if (!checked[i][j]) {
				mp[cnt] = bfs(i, j, cnt);
				cnt++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = arr[i][j];
			if (arr[i][j] == 0) continue;
			map<int, int > mc;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				mc[dist[nx][ny]] = 1;
			}

			map<int, int>::iterator cc;
			for (cc = mc.begin(); cc != mc.end(); ++cc) {
				result[i][j] += mp[cc->first];
			}
		}
	}

	print();
	return 0;
}