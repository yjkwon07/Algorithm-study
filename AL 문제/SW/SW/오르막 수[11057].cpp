#include <iostream>
using namespace std;
/*
	������ �� 
	https://www.acmicpc.net/problem/11057
	
	������ ���� ���� �ڸ��� ���������� �̷�� ���� ���Ѵ�
	������ ���� ���Ƶ� ������������ ģ��
	���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ����
	���� 0���� ������ �� �ִ�.
	��: 1233345, 357, 8888888, 1555999
	D[i][j] = ���̰� i�̰� ������ ���ڰ� j�� ������ ���� ����
	D[1][i] = 1
	D[i][j] += D[i-1][k] (0 <= k <= j)
*/
const long long mod = 10007LL;
long long a[1001][10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) a[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				a[i][j] += a[i - 1][k];
				a[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) ans += a[n][i];
	cout << ans % mod << '\n';
	return 0;
}