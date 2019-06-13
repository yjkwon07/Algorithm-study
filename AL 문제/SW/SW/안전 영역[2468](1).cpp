#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
	BFS 
	안전 영역
	https://www.acmicpc.net/problem/2468
	
	어떤 지역의 높이 정보를 파악
	그 지역의 많은 비가 내렸을때 물에 잠기지 않는 안전한 영역이 최대로 몇개?
		장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다.
		아무 지역도 물에 잠기지 않을 수 있다. 
*/

#define MAX 100
int n;
int max_c;
int ans;
int arr[MAX][MAX];
int checks[MAX][MAX][MAX];

/*
0 : wall
1 over : local state
*/

struct MOVE
{
	int x, y;
};
void print(int k) {
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < n; j++) {
			cout << checks[i][j][k] << ' ';
		}
		cout << '\n';
	}
}

const int dx[] = { 0 ,0 ,1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void rain(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= k) {
				checks[i][j][k] = 0;
			}
		}
	}
}

void bfs(int i, int j, int k, int cnt) {
	queue<MOVE> qu;
	qu.push({ i , j });
	checks[i][j][k] = cnt;
	while (!qu.empty())
	{
		int x = qu.front().x, y = qu.front().y;
		qu.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (checks[nx][ny][k] == -1) {
				checks[nx][ny][k] = cnt;
				qu.push({ nx, ny });
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max_c) {
				max_c = arr[i][j];
			}
		}
	}

	memset(checks, -1, sizeof(checks));
	for (int k = 0; k <= max_c; k++) {
		rain(k);
		int cnt = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (checks[i][j][k] == -1) {
					bfs(i, j, k, cnt);
					cnt++;
				}
			}
		}
		cnt -= 1;
		if (ans < cnt) ans = cnt;
		//		cout << '\n';
		//		cout << k << '\n';
		//		print(k);
	}

	cout << ans << '\n';
	return 0;
}