#include<iostream>
using namespace std;
/*
	1, 2, 3 ���ϱ� 
	https://www.acmicpc.net/problem/9095

	���� n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ����
	D[i] = i �� 1, 2, 3�� ������ ��Ÿ���� ����� ��
	D[i] = D[i-1] + D[i-2] +D[i-3]
*/
int d[11];
int main() {
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {                     
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}
