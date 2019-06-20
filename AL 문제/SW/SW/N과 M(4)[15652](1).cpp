#include<iostream>
using namespace std;
/*
	N��M(4) 
	https://www.acmicpc.net/problem/15652
	
	1���� N���� �ڿ��� �߿��� M���� �� ������ ��� ���ϴ� ����( �ߺ� ���� ����, �񳻸�����)
	1 <= < M <= 8
	�񳻸������� ���� ���̱� ������, �ٸ� ��ĵ� �����ϴ�.
	������ �ڿ����� �����ϴ� ���� �������� �ʴ� ��찡 �ִ�.
	������, �ߺ� ������ �����ϱ� ������, �����ϴ� ��츦 i�� �����ϴ� ���� ����ȭ�ؾ� �Ѵ�.
*/
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(index + 1, i, n, m);
		// i + 1 �ߺ� ������� ����
		// i �ߺ��� ���
		a[index] = 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	cin >> n;
	return 0;
}