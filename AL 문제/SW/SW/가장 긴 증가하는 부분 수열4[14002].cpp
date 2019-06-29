#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
	���� �� �����ϴ� �κ� ����4
	https://www.acmicpc.net/problem/14002

	���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ����
	����
	���� A = {10, 20, 10 ,30 ,20, 50}
	���� �� �����ϴ� �κ� ����A = {10, 20, 10, 30, 20, 50}
*/
void go(int p, vector<int> &v, vector<int> &a) {
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p], v, a);
	cout << a[p] << ' ';
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> d(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = d[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}
	cout << ans << '\n';
	go(p, v, a);
	cout << '\n';
	return 0;
}