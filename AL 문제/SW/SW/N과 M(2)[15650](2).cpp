#include<iostream>
using namespace std;
/*
	N과M(2)
	https://www.acmicpc.net/problem/15650

	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 문제 (오름차순)
	1 <= M <= N <= 8
	code는 2가지 케이스가 나올 수 있다.
	for문(1), selected(2)
*/

int a[10];
// index => 오름차순 값
// selected 몇개를 고름?
void go(int index, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (index > n) return;
	a[selected] = index;
	go(index + 1, selected + 1, n, m);
	a[selected] = 0;
	go(index + 1, selected, n, m);

}

int main() {
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);
	return 0;
}
