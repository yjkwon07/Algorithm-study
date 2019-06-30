#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
	연구소 3  
	https://www.acmicpc.net/problem/17142
	알고리즘 분류 : BFS, 브루트 포스  

	연구소에 바이러스를 퍼트리는 데 걸리는 최소 시간을 구하는 문제다. 
	바이러스를 놓을 수 있는 경우를 모두 만든 후, 각 케이스에 대해 BFS로 바이러스를 퍼트려서 최솟값을 구하면 된다. 
	BOJ 17141번 '연구소 2'와 거의 동일한 문제이다. 일부 값만 수정하면 된다.

	연구소의 사이즈는 N이며, 바이러스의 개수는 M이다.
	바이러스를 놓을 수 있는 칸(2)의 좌표를 별도의 리스트 V에 저장한다.
	빈칸(0)의 개수를 모두 세고, 이를 K라 하자. 이 값은 바이러스를 퍼트려야 하는 칸의 총개수가 된다.
	조합(combination) 방법을 통해 M개의 바이러스를 바이러스 칸(2)에 둔다. 이때 리스트 V를 활용하여, 바이러스를 놓은 칸의 좌표를 큐에 모두 집어넣는다.
	BFS를 통해 바이러스를 감염시킨다. 감염시킬 때마다, 감염시킨 칸의 개수를 세고, 감염 시간을 계속 업데이트한다.
	감염시킬 수 있는 곳은 빈칸(0)만 가능하지만, 바이러스를 놓을 수 있는 칸(2)으로도 이동할 수 있다.
	BFS가 종료된 후, 감염시킨 칸의 개수와 K가 같은지 비교한다. 만약 비교한 값이 같고, 걸린 시간이 최솟값이라면, 정답으로 업데이트한다.
	모든 경우의 수에 대해서 BFS를 수행한다.
*/
struct virus {
	int x, y;
};

int a[50][50], dist[50][50];
int n, m, k, ans = 1e9;
bool select[10];
vector<virus> v;
queue<virus> q;
const int dx[] = { -1, 0 , 1, 0 }, dy[] = { 0, 1, 0, -1 };

void bfs() {
	int infect = 0, times = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (a[nx][ny] != 1 && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				if (a[nx][ny] == 0) {
					infect += 1;
					times = dist[nx][ny];
				}
				q.push({ nx, ny });
			}
		}
	}
	if (infect == k && ans > times) ans = times;
}

void solve(int idx, int cnt, int d) {
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i<d; i++) {
			if (select[i]) {
				q.push({ v[i].x, v[i].y });
				dist[v[i].x][v[i].y] = 0;
			}
		}
		bfs();
		return;
	}
	for (int i = idx; i<d; i++) {
		if (!select[i]) {
			select[i] = true;
			solve(i + 1, cnt + 1, d);
			select[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) v.push_back({ i, j });
			if (a[i][j] == 0) k += 1;
		}
	}
	solve(0, 0, v.size());
	printf("%d\n", ans == 1e9 ? -1 : ans);
	return 0;
}
