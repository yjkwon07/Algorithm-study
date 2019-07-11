#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
/*
	이차원 배열과 연산 
	https://www.acmicpc.net/problem/17140
	알고리즘 분류 : 시뮬레이션

	문제에 주어진 조건을 그대로 구현하는 문제다. 
	여러 개의 변수를 가진 구조체(또는 벡터)를 정렬해야 한다. 
	연산자 오버로딩을 통해 우선순위를 구현하거나, STL pair를 사용하면 된다. 
	정렬 대신, 우선순위 큐를 사용할 수 있다.

	행의 최대 사이즈를 N, 열의 최대 사이즈를 M이라고 하자.
	이 문제는 N >= M일 때 각 행을 정렬하고, N < M일 때 각 열을 정렬한다.
	정렬의 우선순위는 1) 수의 등장 횟수, 2) 해당 숫자이며, 오름차순으로 정렬한다.
	수의 등장 횟수는 별도의 카운터 배열을 만들어서 해당 숫자가 얼마나 등장하는지 센다.
	배열에 값이 들어갈 때는 숫자가 먼저 들어가며, 그다음으로 수의 등장 횟수가 들어간다.
	정렬 연산이 수행되면, 행 또는 열이 커질 수 있다. 커질 때마다 N 또는 M 값을 최대치로 업데이트한다.
	행 연산과 열 연산은 동작이 거의 비슷하다. 그대로 복사 붙여넣기 한 후, 범위와 인덱스만 적절히 수정하면 된다.
	정렬을 수행하다가 A[R][C] == K를 발견하면 현재 시간을 출력하고 종료한다.
	수행 시간이 100을 초과하면, -1을 출력하고 종료한다.
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
