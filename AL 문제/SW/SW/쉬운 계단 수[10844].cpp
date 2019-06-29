#include<iostream>
using namespace std;
/*
	쉬운 계단 수
	https://www.acmicpc.net/problem/10844

	인접한 자리의 차이가 1이 나는 수를 계단 수라고 한다.
	예: 45656
	길이가 N인 계단 수의 개수를 구하는 문제
	Dynamic Programming으로 접근한다.

	첫 째 자리수에 올 수 있는 숫자는 1~9이다.

	만약 첫 째 자리수가 1이라면, 둘 째자리수는 0 또는 2가 올 수 있다.

	만약 첫 째 자리 수가 9라면, 둘 째자리수는 8만 올 수 있다.

	둘 째 자리 수가 0이라면, 셋 째자리수는 1만 올 수 있다.

	길이가 N인 계단 수는, N자리 수일 때 각 숫자 0~9가 올 수 있는 수의 총합이다.


	D[i][j] = 길이가 i이가 마지막 숫자가 j인 계단 수의 개수
	D[i][j] = D[i -1][j-1] + D[i-1][j+1]
*/
const long long mod = 1000000000LL;
int d[101][10];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) ans += d[n][i];
	ans %= mod;
	cout << ans << '\n';
	return 0;
}