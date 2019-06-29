#include <iostream>
using namespace std;
/*
	오르막 수 
	https://www.acmicpc.net/problem/11057
	
	오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다
	인접한 수가 같아도 오름차순으로 친다
	수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 문제
	수는 0으로 시작할 수 있다.
	예: 1233345, 357, 8888888, 1555999
	D[i][j] = 길이가 i이고 마지막 숫자가 j인 오르막 수의 개수
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