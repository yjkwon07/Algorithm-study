#include <cstdio>
#include <vector>
using namespace std;
/*
	감시 

	5종류의 CCTV를 키고 끄면서, CCTV가 감시할 수 없는 영역인 사각지대의 최소 크기를 맞추는 문제다. 
	최대 8개의 CCTV가 주어지고, 각 CCTV는 일정한 방향성을 가지고 있다. 
	CCTV는 90도로 회전하며 사용할 수 있고, 이에 따라서 감시 영역이 바뀐다. 
	이 문제는 N이 최대 8이기 때문에, 모든 경우의 수를 구해서 최소 크기를 구하면 된다.
	
	CCTV 1~5번에 해당하는 방향을 만든다. 아래 코드에서는 비트 연산을 통해 만들었다.
	위쪽 방향 : 0001 == 1<<0 (인덱스 0)
	오른쪽 방향 : 0010 == 1<<1 (인덱스 1)
	아래쪽 방향 : 0100 == 1<<2 (인덱스 2)
	왼쪽 방향 : 1000 == 1<<3 (인덱스 3)
	위 4가지를 정하고, OR 연산을 통해 각 CCTV의 방향성을 정했다.
	DFS 방식으로 CCTV의 개수만큼 깊이 탐색을 시작한다.
	각 CCTV를 키고 끄는 방식으로 모든 경우의 수를 구한다.
	CCTV를 키면 해당 CCTV에 대한 방향성을 토대로 감시 영역을 정해야 한다.
	이 경우, a배열에 원래 맵 정보가 들어있고, b배열을 별도로 만들어서 CCTV의 감시 정보를 저장했다.
	CCTV는 벽(6)을 관통할 수 없다. 맵의 범위를 벗어나는 것을 처리하는 것은, 가장자리를 모두 벽(6)으로 만들면 편하다.
*/
struct cctv {
	int x, y, id;
};

int n, m, ans = 1e9;
int a[10][10], b[10][10];
vector<cctv> v;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
const int U = 1, R = 1 << 1, D = 1 << 2, L = 1 << 3;
vector<int> direct[6] = { {},
{ U, R, D, L }, // CCTV 1 : One direction
{ U | D, R | L },   // CCTV 2 : Two direction (180 degree)
{ U | R, R | D, D | L, L | U },         // CCTV 3 : Two direction (90 degree)
{ L | U | R, U | R | D, R | D | L, D | L | U }, // CCTV 4 : Three direction
{ U | R | D | L } };   // CCTV 5 : Four direction

void observe(int x, int y, int i, int d) {
	// CCTV observation. d==1(On), d==-1(off)
	for (int k = 0; k<4; k++) {
		if (i & (1 << k)) {
			int nx = x, ny = y;
			while (a[nx][ny] != 6) {
				b[nx][ny] += d;
				nx += dx[k], ny += dy[k];
			}
		}
	}
}

void solve(int index) {
	if (index == (int)v.size()) {
		// Count blind areas.
		int area = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (b[i][j] == 0) area += 1;
			}
		}
		if (ans > area) ans = area;
		return;
	}
	int x = v[index].x, y = v[index].y, id = v[index].id;
	for (auto i : direct[id]) {
		observe(x, y, i, 1);  // Turn on cctv.
		solve(index + 1);
		observe(x, y, i, -1); // Turn off cctv.
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n + 2; i++) {
		for (int j = 0; j<m + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) a[i][j] = 6;
			else {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 6) b[i][j] = 1;
				else if (a[i][j] != 0) v.push_back({ i, j, a[i][j] });
			}
		}
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}