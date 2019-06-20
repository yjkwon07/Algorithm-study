#include<iostream>
#include<algorithm>
using namespace std;
/*
	N과M(6)
	https://www.acmicpc.net/problem/15655
	
	N과 M(2)
	N개의 서로 다른 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(오름차순)
	1 <= M <= N <= 8
*/
int a[10];
int num[10];

void go(int index, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= n) return;
	a[selected] = index;
	go(index + 1, selected + 1, n, m);
	a[selected] = 0;
	go(index + 1, selected, n, m);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	go(0, 0, n, m);
	cin >> n;
	return 0;
}