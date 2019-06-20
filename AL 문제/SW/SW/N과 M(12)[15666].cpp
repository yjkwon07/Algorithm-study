#include<iostream>
#include<algorithm>
using namespace std;
/*
	N과M(12)
	https://www.acmicpc.net/problem/15666
	
	N개의 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(중복 선택 가능, 비내림차순)
	1 <= M <= N <= 8
	이 문제는 N과M(4)과 동일한 문제이다.
	N개의 자연수에서 중복되는 수를 제거한 다음에 문제를 해결하면 된다.
*/
int a[10];
int num[10];
int temp[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > m) return;
	for (int i = start; i < n; i++) {
		a[index] = i;
		go(index + 1, i, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && temp[i] == temp[i - 1]) continue;
		num[k++] = temp[i];
	}
	n = k;
	go(0, 0, n, m);
	return 0;
}