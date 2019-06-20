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
int cnt[10]; // i�� �?
void go(int index, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt[i]; j++) {
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}
	if (index > n) return;
	for (int i = m - selected; i >= 1; i--) { // i: ���� ��ĭ�� ���� ~ 1����
											  // �� ū��? ->  ���������� �����ϴ� ���̱� ������
		cnt[index] = i;
		go(index + 1, selected + i, n, m);
	}
	cnt[index] = 0;
	go(index + 1, selected, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	go(1, 0, n, m);
	cin >> n;
	return 0;
}