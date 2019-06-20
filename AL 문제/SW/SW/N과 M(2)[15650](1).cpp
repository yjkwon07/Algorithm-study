#include <iostream>
using namespace std;
/*
	N과M(2)
	https://www.acmicpc.net/problem/15650

	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 문제 (오름차순)
	1 <= M <= N <= 8
	code는 2가지 케이스가 나올 수 있다.
	for문(1), selected(2)
*/

bool c[10];
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i<m; i++) {
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(index + 1, i + 1, n, m);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}