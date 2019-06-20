#include <iostream>
using namespace std;
/*
	N��M(2)
	https://www.acmicpc.net/problem/15650

	1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ������ ��� ���ϴ� ���� (��������)
	1 <= M <= N <= 8
	code�� 2���� ���̽��� ���� �� �ִ�.
	for��(1), selected(2)
*/

bool c[10];
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i<m; i++) {
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(index + 1, i + 1, n, m);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}