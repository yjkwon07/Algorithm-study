#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	연속합 2 
	https://www.acmicpc.net/problem/13398
	
	d[i] = 왼쪽에서부터 구한 연속한 정답
	dr[i] = 오른쪽에서부터 구한 연속한 정답
	각각의 제거할 수 k에대해서 dl[k-1] + dr[k+1]의 최대값이 정답이 된다
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}

	vector<int> c(n);
	for (int i = n - 1; i >= 0; i--) {
		c[i] = a[i];
		if (i == n - 1) continue;
		if (c[i] < c[i + 1] + a[i]) {
			c[i] = c[i + 1] + a[i];
		}
	}
	int ans = d[0];
	for (int i = 1; i < n; i++) {
		if (ans < d[i])
			ans = d[i];
	}
	for (int i = 1; i < n - 1; i++) {
		if (ans < d[i - 1] + c[i + 1]) {
			ans = d[i - 1] + c[i + 1];
		}
	}
	cout << ans << '\n';
	return 0;
}