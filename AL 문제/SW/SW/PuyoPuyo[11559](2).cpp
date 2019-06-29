#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/*
	PuyoPuyo
	알고리즘 분류 : BFS, 시뮬레이션

	게임 '뿌요 뿌요'를 프로그래밍하는 문제다. 
	주어진 뿌요뿌요 판에서 얼마나 많은 연쇄가 일어나는지 맞춰야 한다. 
	BFS를 통해 전체 탐색을 하고, 터트릴 수 있는 블록이 있는지 확인하면서, 4개 이상이면 터트리고 아래로 떨어뜨리면 된다.


	1. 아래에서부터 블록(R,G,B,P,Y)을 확인한다. 빈 공간(.)은 무시한다.
	2. 블록을 발견하면, BFS 탐색을 통해 같은 색깔의 블록이 몇 개나 인접해있는지 확인한다.
	3. 만약 인접한 블록이 4개 이상이면, 서로 연결된 블록을 모두 터트린다. 터트린 블록은 빈 공간으로 만든다.
	4. 위쪽 끝까지 1~3 과정을 반복한다.
	5. 만약 블록이 한 번이라도 터졌다면, 정답 카운트를 1 증가시키고, 아래로 떨어질 수 있는 블록이 있는지 확인하고 떨어뜨린다.
	블록이 한 번이라도 터졌다면, 1~5 과정을 반복한다. 만약 한 번도 안 터졌다면 프로그램을 종료한다.
*/
struct puyo {
	int x, y;
};

const int n = 12, m = 6;
char a[n][m + 1];
bool check[n][m + 1];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void fall() {
	// Puyo blocks fall down.
	for (int j = 0; j<m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == '.') continue;
			for (int k = n - 1; k >= i; k--) {
				if (a[k][j] == '.') {
					a[k][j] = a[i][j];
					a[i][j] = '.';
				}
			}
		}
	}
}

bool bfs(int i, int j, char c) {
	queue<puyo> q;
	vector<puyo> block;
	q.push({ i, j });
	check[i][j] = true;
	block.push_back({ i, j });
	// Count same blocks
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny] || a[nx][ny] != c) continue;
			check[nx][ny] = true;
			block.push_back({ nx, ny });
			q.push({ nx, ny });
		}
	}
	// Crash blocks if block >= 4
	if ((int)block.size() >= 4) {
		for (auto k : block) a[k.x][k.y] = '.';
		return true;
	}
	else return false;
}

bool crash() {
	// Find out if exist blocks which can be crashed.
	bool crashed = false;
	memset(check, false, sizeof(check));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (check[i][j] || a[i][j] == '.') continue;
			if (bfs(i, j, a[i][j])) crashed = true;
		}
	}
	return crashed;
}

void solve() {
	int ans = 0;
	while (crash()) {
		fall();
		ans += 1;
	}
	printf("%d\n", ans);
}

int main() {
	for (int i = 0; i<n; i++) scanf("%s", a[i]);
	solve();
	return 0;
}