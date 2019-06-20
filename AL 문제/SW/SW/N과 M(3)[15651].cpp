#include<iostream>
using namespace std;
/*
	N��M(3)
	https://www.acmicpc.net/problem/15651

	1���� N���� �ڿ��� �߿��� M���� �� ������ ��� ���ϴ� ���� (�ߺ� ���� ����)
	1 < = M <= N <= 7
*/
int a[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		a[index] = i;
		go(index + 1, n, m);
		a[index] = 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	return 0;
}