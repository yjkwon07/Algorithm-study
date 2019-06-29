#include <iostream>
using namespace std;
/*
	�������� ��
	https://www.acmicpc.net/problem/1699
	�־��� �ڿ��� N�� ���������� ������ ǥ���� ���� �� ���� �ּҰ����� ���ϴ� ����
	11 = 3^2 + 1^2 + 1^2

	D[i] = i�� �������� ������ ��Ÿ���� ��, �ʿ��� ���� �ּ� ����
	D[i] = min(D[i-j^2] +1) ( 1<= i <= j ^2)
*/
long long a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (a[i] > a[i - j * j] + 1)
				a[i] = a[i - j * j] + 1;
		}
	}

	cout << a[n];
	return 0;
}