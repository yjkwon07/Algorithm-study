#include<iostream>
#include<algorithm>
using namespace std;
/*
	 N과M(10) 
	 https://www.acmicpc.net/problem/15664
	
	N개 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(비내림차순)
	1 <= M <= N <=8
	모든 수열을 구한 다음, 중복을 제거하는 방식으로 풀 수 있다..
	N과 M(2) 문제풀이 + 중복 제거
*/
int num[10];
int cnt[10];
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << num[a[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		if (cnt[i] > 0) {
			cnt[i] -= 1;
			a[index] = i;
			go(index + 1, i, n, m);
			cnt[i] += 1;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int temp[10];
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);

	int k = 0;
	int x = temp[0];
	int c = 1;
	for (int i = 1; i < n; i++) {
		if (x == temp[i]) {
			c += 1;
		}
		else {
			num[k] = x;
			cnt[k] = c;
			k += 1;
			x = temp[i];
			c = 1;
		}
	}
	num[k] = x;
	cnt[k] = c;
	n = k + 1;
	go(0, 0, n, m);
	return 0;
}