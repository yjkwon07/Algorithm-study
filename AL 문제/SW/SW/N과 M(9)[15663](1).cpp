#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	N과M(9) 
	https://www.acmicpc.net/problem/15663
	
	N개의 자연수 중에서 M개를 고른 수열을 모두 구하는 문제(중복순열 제거)
	1 <= M <= N <= 8
	모든 수열을 구한 다음, 중복을 제거하는 방식으로 풀 수 있다.
	-> 출제가 원하는 답 아님
	N과M(1)문제풀이 - 중복제거
	cnt => 수를 k번 사용한다
*/
int a[10];
int num[10];
int c[10];
vector<vector<int>> d;
void go(int index, int n, int m) {
	if (index == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			temp.push_back(num[a[i]]);
		}
		d.push_back(temp);
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
	for (int i = 0; i<n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	go(0, n, m);
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	for (auto &v : d) {
		for (int i = 0; i<m; i++) {
			cout << v[i];
			if (i != m - 1) {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}