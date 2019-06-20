#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	N��M(9) 
	https://www.acmicpc.net/problem/15663
	
	N���� �ڿ��� �߿��� M���� �� ������ ��� ���ϴ� ����(�ߺ����� ����)
	1 <= M <= N <= 8
	��� ������ ���� ����, �ߺ��� �����ϴ� ������� Ǯ �� �ִ�.
	N��M(1)����Ǯ�� - �ߺ�����
	cnt => ���� k�� ����Ѵ�
*/
int a[10];
int num[10];
int cnt[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] > 0) {
			cnt[i] -= 1;
			a[index] = i;
			go(index + 1, n, m);
			cnt[i] += 1;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int temp[10];
	for (int i = 0; i<n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);
	int k = 0;
	int x = temp[0];
	int c = 1;
	for (int i = 1; i<n; i++) {
		if (x == temp[i]) {
			c += 1;
		}
		else {
			num[k] = x;
			cnt[k] = c;
			k += 1;
			x = temp[i];
			c = 1;
		}
	}
	num[k] = x;
	cnt[k] = c;
	n = k + 1;
	go(0, n, m);
	return 0;
}