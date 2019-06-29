#include <iostream>
using namespace std;
/*
	�պ���
	https://www.acmicpc.net/problem/2225

	0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����Ǽ�
	D[k][N] = 0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����Ǽ�
	? + ? + ? + ��. + ? + L =N
	���� ���� ��Ÿ���� ��:D[K-1][N-L]
	D[K][N] = SUM(D[K-1][N-L])(0 <= L <= N)
	O(kN^2)
*/
long long d[5001][5001];
long long mod = 1000000000;
int main() {
	int n, k;
	cin >> n >> k;
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			d[i][j] = d[i - 1][j];
			if (j - 1 >= 0) {
				d[i][j] += d[i][j - 1];
			}
			d[i][j] %= mod;
		}
	}
	cout << d[k][n] << '\n';
	return 0;
}

