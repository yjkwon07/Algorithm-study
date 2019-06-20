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
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(index + 1, i, n, m);
		// i + 1 중복 허용하지 않음
		// i 중복을 허용
		a[index] = 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	cin >> n;
	return 0;
}