#include<iostream>
using namespace std;
/*
	N 과M(1)
	https://www.acmicpc.net/problem/15649

	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 문제
	1 <= M <= N <= 8

	중복을 피해야 하기 때문에 c라는 배열을 만들어 방문을 했는지 체크를 한다.
	따라서 a의 i의 값을 c배열의 인덱스로 대입을 한다.
	index 가 m + 1 ( 1부터 시작하기 때문)에 도달 하게 된다면 출력을 하게 된다.
*/
int a[10];
bool c[10];
void go(int index, int n, int m) {
	if (index == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
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
	go(1, n, m);
	return 0;
}