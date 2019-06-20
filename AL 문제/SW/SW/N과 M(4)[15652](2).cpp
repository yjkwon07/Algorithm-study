#include<iostream>
using namespace std;
/*
	N과M(4)
	https://www.acmicpc.net/problem/15652

	1부터 N까지 자연수 중에서 M개를 고른 수열을 모두 구하는 문제( 중복 선택 가능, 비내림차순)
	1 <= < M <= 8
	비내림차순만 고르는 것이기 때문에, 다른 방식도 가능하다.
	각각의 자연수를 선택하는 경우와 선택하지 않는 경우가 있다.
	하지만, 중복 선택이 가능하기 때문에, 선택하는 경우를 i개 선택하는 경우로 세분화해야 한다.
*/
int cnt[10]; // i를 몇개?
void go(int index, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt[i]; j++) {
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}
	if (index > n) return;
	for (int i = m - selected; i >= 1; i--) { // i: 남은 빈칸의 개수 ~ 1까지
											  // 왜 큰수? ->  사전순으로 증가하는 순이기 때문에
		cnt[index] = i;
		go(index + 1, selected + i, n, m);
	}
	cnt[index] = 0;
	go(index + 1, selected, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	go(1, 0, n, m);
	cin >> n;
	return 0;
}