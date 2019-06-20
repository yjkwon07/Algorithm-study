#include<iostream>
#include<algorithm>
using namespace std;
/*
	N과 M(7)
	https://www.acmicpc.net/problem/15656

	N과 M(3)
	N개의 서로 다른 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(중복 가능)
	1 <=  M <= N <= 7
*/
int a[10];
int num[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		a[index] = i;
		go(index + 1, n, m);
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