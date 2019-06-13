#include <cstdio>
#define MAX 502
/*
	������ 1ȣ
	https://www.acmicpc.net/problem/3987
	������ 1ȣ�� �ñ׳��� ������ Ž���� �� �ִ� �ִ� �Ÿ��� ����ϴ� ������. 
	������ �־��� ������ �״�� �����ϸ� �ȴ�. ���� ó���� ���ڷ� ó���ϸ� �����ϴ�.

	������ ��(U), ��(R), ��(D), ��(L) ������ �����.
	U, R, D, L�� �ε����� 0, 1, 2, 3���� �д�.
	�Է¹��� ��, �����ڸ��� ��� ��Ȧ('C')�� �����θ� ���� ���� ó���ϱ� ����.
	'/'�� ������ ���, 0 �� 1, 1 �� 0, 2 �� 3, 3 �� 2�� ������ ���Ѵ�. -> P[]
	'\'�� ������ ���, 0 �� 3, 1 �� 2, 2 �� 1, 3 �� 0���� ������ ���Ѵ�. -> Q[]
	
	���� ��ȯ�� �迭�� �ε����� ������ ó���ϸ� �ȴ�.
	�־��� ���������� 4�������� ������, �̵��� ���� ������ ���� �����Ѵ�.
	���� ������ ���鼭 ��� �̵��ϰ�, ���� ��ǥ�� ��Ȧ�� ��� ������ �������´�.
	����, �ñ׳��� ���������� �ٽ� ���ƿ���, ó�� ��� ����� ���� ���, ���� ������ �� ���̹Ƿ� 'Voyager'�� ����Ѵ�.
	�� ���⿡�� �ִ� �Ÿ��� �����Ѵ�.
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