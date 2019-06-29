#include<iostream>
using namespace std;
int a[1000];
/*
	2 * N Ÿ�ϸ� 
	https://www.acmicpc.net/problem/11726
	
	2 *  N ���簢���� 1 * 2,  2 * 1Ÿ�Ϸ� ä��� ����� ��
	�Ʒ� �׸��� 2 * 5�� ä��� ����� ��
	D[i] = 2 * i���簢���� ä��� ����� ��
*/
// top
int go(int x) {
	if (x == 0) return 1;
	if (x == 1) return 1;
	if (a[x] > 0) return a[x];
	a[x] = go(x - 1) + go(x - 2);
	return a[x] %= 10007;
}
// bottom
int go2(int n) {
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
		a[i] %= 10007;
	}
	return a[n];
}

int main() {
	int n;
	cin >> n;
	cout << go(n);
}