#include<iostream>
#include<algorithm>
using namespace std;
/*
	N과 M(5)
	https://www.acmicpc.net/problem/15654
	
	N과 M(1)
	N개의 서로 다른 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(중복 제거)
	1 <= M <= N <= 8
*/
int a[10];
int num[10];
int c[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << num[a[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	go(0, n, m);
	cin >> n;
	return 0;
}