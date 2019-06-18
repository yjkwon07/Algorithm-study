#include <cstdio>
#include <vector>
#include <set>
using namespace std;
/*
	벽 부수고 이동하기4
	https://www.acmicpc.net/problem/16946
	
	알고리즘 분류 : DFS, BFS  

	벽 부수고 이동하기 네 번째 문제다. 이번 문제는 이전 문제들과 완전히 다르다. 플러드 필 알고리즘을 구현하는 문제이다.

	기본 아이디어
	기본적으로, 각 벽(1)부터 DFS를 시작하여 빈칸(0)을 향해 뻗어나가는 방식을 생각할 수 있다.
	구현은 간단하지만, 최대 1000*1000 사이즈가 입력으로 주어지므로 시간 초과가 난다.

	개선 아이디어
	배열 A를 DFS를 통해 완전 탐색한다.
	1. 빈칸(0)부터 시작하여 인접한 빈칸의 개수를 모두 세면서 리스트 V에 기록해둔다.
	2. 빈칸의 개수를 셀 때, 배열 B에 각 빈칸마다 넘버링을 해둔다.
	1~2 과정을 맵 전체에 한다.
	배열 A에서 각 벽(1)마다 인접한 4칸을 확인하고, 배열 B를 통해 저장해둔 넘버링이 있는지 확인한다.
	Set 자료구조를 통해 중복이 없도록 인접한 넘버링을 기록해둔다.
	각 벽(1)마다 넘버링에 해당하는 리스트 V의 값을 모두 더한다.
*/
int n, m;
int a[1001][1001], b[1000][1000];
bool check[1000][1000];
vector<int> v;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int dfs(int x, int y, int z) {
	b[x][y] = z;
	int ret = 1;
	check[x][y] = true;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (!check[nx][ny] && !a[nx][ny]) ret += dfs(nx, ny, z);
	}
	return ret;
}

void solve() {
	// Flood-fill
	int z = 1;
	v.push_back(0);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (!a[i][j] && !check[i][j]) {
				v.push_back(dfs(i, j, z));
				z += 1;
			}
		}
	}
	// Add sum to wall
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j]) {
				set<int> s;
				for (int k = 0; k<4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					s.insert(b[ni][nj]);
				}
				for (auto k : s) a[i][j] += v[k];
			}
		}
	}
	// Print
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			printf("%d", a[i][j] % 10);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	solve();
	return 0;
}