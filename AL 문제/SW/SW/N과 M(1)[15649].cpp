#include<iostream>
using namespace std;
/*
	N ��M(1)
	https://www.acmicpc.net/problem/15649

	1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ������ ��� ���ϴ� ����
	1 <= M <= N <= 8

	�ߺ��� ���ؾ� �ϱ� ������ c��� �迭�� ����� �湮�� �ߴ��� üũ�� �Ѵ�.
	���� a�� i�� ���� c�迭�� �ε����� ������ �Ѵ�.
	index �� m + 1 ( 1���� �����ϱ� ����)�� ���� �ϰ� �ȴٸ� ����� �ϰ� �ȴ�.
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