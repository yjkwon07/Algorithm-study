#include<iostream>
#include<algorithm>
using namespace std;
/*
	N�� M(7)
	https://www.acmicpc.net/problem/15656

	N�� M(3)
	N���� ���� �ٸ� �ڿ��� �߿��� M���� �� ������ ��� ���ϴ� ����(�ߺ� ����)
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