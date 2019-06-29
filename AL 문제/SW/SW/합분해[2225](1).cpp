#include<iostream>
#include<algorithm>
using namespace std;
/*`		
	�պ��� 
	https://www.acmicpc.net/problem/2225
	
	0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����Ǽ� 
	D[k][N] = 0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����Ǽ�
	? + ? + ? + ��. + ? + L =N
	���� ���� ��Ÿ���� ��:D[K-1][N-L]
	D[K][N] = SUM(D[K-1][N-L])(0 <= L <= N)
	O(kN^2)
*/
long long a[210][210];
long long mod = 1000000000LL;

int main() {
	int n, k;
	cin >> n >> k;
	a[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int x = 0; x <= n; x++) {
			for (int j = 0; j <= x; j++) {
				a[i][x] += a[i - 1][j];
				a[i][x] %= mod;
			}
		}

	}

	cout << a[k][n];
	return 0;
}