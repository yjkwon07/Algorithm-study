#include <cstdio>
#define MAX 502
/*
	보이저 1호
	https://www.acmicpc.net/problem/3987
	보이저 1호가 시그널을 보내서 탐사할 수 있는 최대 거리를 출력하는 문제다. 
	문제에 주어진 조건을 그대로 구현하면 된다. 방향 처리는 숫자로 처리하면 간단하다.

	방향을 상(U), 우(R), 하(D), 좌(L) 순서로 만든다.
	U, R, D, L의 인덱스를 0, 1, 2, 3으로 둔다.
	입력받을 때, 가장자리를 모두 블랙홀('C')로 만들어두면 범위 밖을 처리하기 쉽다.
	'/'를 만났을 경우, 0 → 1, 1 → 0, 2 → 3, 3 → 2로 방향이 변한다. -> P[]
	'\'를 만났을 경우, 0 → 3, 1 → 2, 2 → 1, 3 → 0으로 방향이 변한다. -> Q[]
	
	방향 전환은 배열의 인덱스와 값으로 처리하면 된다.
	주어진 시작점에서 4방향으로 돌리고, 이동은 무한 루프를 통해 구현한다.
	무한 루프를 돌면서 계속 이동하고, 다음 좌표가 블랙홀일 경우 루프를 빠져나온다.
	만약, 시그널이 시작점으로 다시 돌아오고, 처음 출발 방향과 같은 경우, 무한 루프를 돌 것이므로 'Voyager'를 출력한다.
	각 방향에서 최대 거리를 저장한다.
*/
int n, m, sx, sy, dist, direct;
char arr[MAX][MAX];
const char D[] = { 'U', 'R', 'D','L' };
const int dx[] = { -1, 0 , 1, 0 };
const int dy[] = { 0 , 1, 0 ,-1 };
const int P[] = { 1, 0 , 3, 2 };
const int Q[] = { 3, 2, 1, 0 };

void solve() {
	for (int i = 0; i < 4; i++) {
		// cnt => checking max count 
		int x = sx, y = sy, cnt = 1, k = i;
		while (arr[x + dx[k]][y + dy[k]]) {
			x += dx[k], y += dy[k];
			if (arr[x][y] == '/') k = P[k];
			else if (arr[x][y] == '\\') k = Q[k];
			cnt += 1;
			// rollback
			if (x == sx && y == sy && k == i) {
				printf("%c\nVoyager\n", D[i]);
				return;
			}
		}
		if (dist < cnt) {
			dist = cnt; 
			direct = i;
		}
	}
	printf("%c\n%d\n", D[direct], dist);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1s", &arr[i][j]);
			if (arr[i][j] == 'C') arr[i][j] = 0;
		}
	}
	scanf("%d %d", &sx, &sy);
	solve();
	return;
}