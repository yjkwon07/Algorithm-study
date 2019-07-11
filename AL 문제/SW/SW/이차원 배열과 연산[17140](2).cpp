#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
/*
	������ �迭�� ���� 
	https://www.acmicpc.net/problem/17140
	�˰��� �з� : �ùķ��̼�

	������ �־��� ������ �״�� �����ϴ� ������. 
	���� ���� ������ ���� ����ü(�Ǵ� ����)�� �����ؾ� �Ѵ�. 
	������ �����ε��� ���� �켱������ �����ϰų�, STL pair�� ����ϸ� �ȴ�. 
	���� ���, �켱���� ť�� ����� �� �ִ�.

	���� �ִ� ����� N, ���� �ִ� ����� M�̶�� ����.
	�� ������ N >= M�� �� �� ���� �����ϰ�, N < M�� �� �� ���� �����Ѵ�.
	������ �켱������ 1) ���� ���� Ƚ��, 2) �ش� �����̸�, ������������ �����Ѵ�.
	���� ���� Ƚ���� ������ ī���� �迭�� ���� �ش� ���ڰ� �󸶳� �����ϴ��� ����.
	�迭�� ���� �� ���� ���ڰ� ���� ����, �״������� ���� ���� Ƚ���� ����.
	���� ������ ����Ǹ�, �� �Ǵ� ���� Ŀ�� �� �ִ�. Ŀ�� ������ N �Ǵ� M ���� �ִ�ġ�� ������Ʈ�Ѵ�.
	�� ����� �� ������ ������ ���� ����ϴ�. �״�� ���� �ٿ��ֱ� �� ��, ������ �ε����� ������ �����ϸ� �ȴ�.
	������ �����ϴٰ� A[R][C] == K�� �߰��ϸ� ���� �ð��� ����ϰ� �����Ѵ�.
	���� �ð��� 100�� �ʰ��ϸ�, -1�� ����ϰ� �����Ѵ�.
*/
int r, c, k, n = 3, m = 3;
int cnt[101], a[101][101];

void solve() {
	for (int t = 0; t<101; t++) {
		if (a[r][c] == k) {
			printf("%d\n", t);
			return;
		}
		if (n >= m) {
			for (int i = 1; i <= n; i++) {
				priority_queue<pair<int, int>> pq;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= m; j++) {
					if (a[i][j]) {
						cnt[a[i][j]] += 1;
						a[i][j] = 0;
					}
				}
				for (int j = 1; j <= 100; j++) {
					if (cnt[j]) pq.push(make_pair(-cnt[j], -j));
				}
				int len = pq.size() * 2;
				m = max(m, len);
				for (int j = 1; j <= len; j += 2) {
					a[i][j] = -pq.top().second;
					a[i][j + 1] = -pq.top().first;
					pq.pop();
				}
			}
		}
		else {
			for (int i = 1; i <= m; i++) {
				priority_queue<pair<int, int>> pq;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= n; j++) {
					if (a[j][i]) {
						cnt[a[j][i]] += 1;
						a[j][i] = 0;
					}
				}
				for (int j = 1; j <= 100; j++) {
					if (cnt[j]) pq.push(make_pair(-cnt[j], -j));
				}
				int len = pq.size() * 2;
				n = max(n, len);
				for (int j = 1; j <= len; j += 2) {
					a[j][i] = -pq.top().second;
					a[j + 1][i] = -pq.top().first;
					pq.pop();
				}
			}
		}
	}
	printf("-1\n");
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	return 0;
}
