#include<iostream>
using namespace std;
/*
	N��M(2)
	https://www.acmicpc.net/problem/15650

	1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ������ ��� ���ϴ� ���� (��������)
	1 <= M <= N <= 8
	code�� 2���� ���̽��� ���� �� �ִ�.
	for��(1), selected(2)
*/

int a[10];
// index => �������� ��
// selected ��� ��?
void go(int index, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (index > n) return;
	a[selected] = index;
	go(index + 1, selected + 1, n, m);
	a[selected] = 0;
	go(index + 1, selected, n, m);

}

int main() {
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);
	return 0;
}
