#include <iostream>
#include <math.h>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
/*
	등산로 조성
	DFS + 백트래킹을 이용하여 모든 경우를 탐색하는 완전탐색 문제이다
	시작 봉우리가 최대 5개이므로 이 지점부터 모든 경우를 탐색한다

	만약 자기보다 높이가 높거나 같은 봉우리를 만났을 경우, 아직 등산로를 한번도 변경한 적이 없다면 해당 지형을 깎는다

	등산로의 최대 길이는 21 까지 나올 수 있다
*/
int testcase;
int n, k;
int ans, highest;
int map[8][8];
int visited[8][8];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int cnt, int cut) {
	// 최대값 갱신
	ans = max(ans, cnt);

	// DFS 탐색
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 맵 밖을 벗어난다면
		if (nx<0 || ny<0 || nx >= n || ny >= n) continue;

		// 이미 방문한 지형이라면
		if (visited[nx][ny]) continue;

		// 현재 지형보다 높거나 같은 지형을 만난 경우
		if (map[x][y] <= map[nx][ny]) {
			if (cut == 0) {
				// 지형을 1 ~ k 만큼 깎아내림
				for (int depth = 1; depth <= k; depth++) {
					int tmp = map[nx][ny];
					int land = map[nx][ny] - depth;

					// 새로 깎은 지형이 현재 지형보다 낮다면
					if (map[x][y] > land) {
						visited[nx][ny] = true;
						map[nx][ny] = land;
						dfs(nx, ny, cnt + 1, cut + 1);
						map[nx][ny] = tmp;
						visited[nx][ny] = false;
					}
				}
			}
		}
		// 현재 지형보다 낮은 지형을 만난 경우
		else {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, cut);
			visited[nx][ny] = false;
		}
	}
}

int main(int argc, const char * argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> k;

		highest = 0;

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cin >> map[i][j];

				// 가장 높은 등산로의 높이를 구함
				highest = max(highest, map[i][j]);
			}
		}

		memset(visited, false, sizeof(visited));

		ans = 0;

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				// 아직 방문하지 않은 가장 높은 등산로일 경우 탐색 시작
				if (map[i][j] == highest && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j, 1, 0);
					visited[i][j] = false;
				}
			}
		}

		// 정답 출력
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}