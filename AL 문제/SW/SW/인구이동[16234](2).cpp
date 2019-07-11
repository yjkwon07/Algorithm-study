#include<cstdio>
#include<cstring>
#define abs(x) (((x) > 0) ? (x) : (- (x)))
using namespace std;
/*
	rebas
	문제 설명

	알고리즘 분류: DFS

	인접한 국각 간의 연합을 통해 인구 이동을 하는 문제다.
	연합은 인접한 두 국가 간의 인구 차이가 L 이상, R 이하일 때만
	가능하다. 인구 차이가 이 범위를 벗어난다면 연합을 할 수 없고,
	인구 이동을 할 수 없다. 이 문제는 그래프에서 연결 요소 개수를 찾는 문제와 비슷하다.

	- DFS를 통해 연합 간은한 국가가 몇 개인지 찾는다. (1, 1)부터 (N, N)까지 전체 국가를 탐색하면서
	방문하지 않은 국가라면 DFS를 호출한다.
	- DFS 탐색을 진행하면서 연합 가능한 국각가 있다면, 연합 국가 개수를 카운트 하고, 인구 수의 합을 저장한다.
	- 또한 DFS 탐색을 하면서 별도로 연합 국가의 경로를 기록해둔다.
	아래 소스코드에서는 moving이라는 이름의 배열을 사용했다.
	- 한 번의 DFS 탐색이 끝나면, 카운트가 1이 넘는지 확인한다.
	카운트가 1이 넘는다면 연합 가능한 국가가 있는 것이므로, 인구를 이동시킨다.
	- 위 과정을 반복하면서, 인구 이동에 변화가 없다면 종료한다.

*/
struct nation {
	int x, y;
};

int n, l, r, cnt, ans;
int a[50][50];
bool check[50][50], moving[50][50];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0 ,-1 };

int dfs(int x, int y) {
	check[x][y] = true;
	int population = a[x][y];
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		int diff = abs(a[x][y] - a[nx][ny]);
		if (diff <  l || diff > r || check[nx][ny]) continue;
		moving[nx][ny] = true;
		cnt++;
		population += dfs(nx, ny);
	}
	return population;
}

void migrate(int p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (moving[i][j]) {
				a[i][j] = p;
				moving[i][j] = false;
			}
		}
	}
}

void solve() {
	int ans = 0;
	while (true) {
		bool moved = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					cnt = 1;
					int population = dfs(i, j) / cnt;
					if (cnt > 1) {
						a[i][j] = population;
						migrate(population);
						moved = true;
					}
				}
			}
		}
		if (moved) ans++;
		else break;
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	return 0;
}