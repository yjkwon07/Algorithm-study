#include<iostream>
#include<algorithm>
using namespace std;
/*`		
	합분해 
	https://www.acmicpc.net/problem/2225
	
	0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의수 
	D[k][N] = 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의수
	? + ? + ? + …. + ? + L =N
	위의 식이 나타내는 값:D[K-1][N-L]
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