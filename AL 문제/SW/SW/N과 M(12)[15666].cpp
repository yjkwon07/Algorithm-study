#include<iostream>
#include<algorithm>
using namespace std;
/*
	N��M(12)
	https://www.acmicpc.net/problem/15666
	
	N���� �ڿ��� �߿��� M���� �� ������ ��� ���ϴ� ����(�ߺ� ���� ����, �񳻸�����)
	1 <= M <= N <= 8
	�� ������ N��M(4)�� ������ �����̴�.
	N���� �ڿ������� �ߺ��Ǵ� ���� ������ ������ ������ �ذ��ϸ� �ȴ�.
*/
int a[10];
int num[10];
int temp[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > m) return;
	for (int i = start; i < n; i++) {
		a[index] = i;
		go(index + 1, i, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && temp[i] == temp[i - 1]) continue;
		num[k++] = temp[i];
	}
	n = k;
	go(0, 0, n, m);
	return 0;
}