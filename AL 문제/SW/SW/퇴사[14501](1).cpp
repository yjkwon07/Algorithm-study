#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	퇴사
	https://www.acmicpc.net/problem/14501
	
	N + 1일이 되는 날 퇴사를 하려고 한다(1<= N <= 15)
	남은 N일 동안 최대한 많은 상담을 하려고 한다
	하루에 하나의 상담을 할 수 있고
	i일에 상담을 하면, T[i]일이 걸리고 P[i]원을 번다.
	go(day, sum)
	day일이 되었다, day일에 있는 상담을 할지 말지 결정해야 한다.
	지금까지 얻은 수익은 sum이다.

*/
int g[21];
int h[21];
int n;
int ans = 0;
void dobi_is_free(int day, int sum) {
	if (day == n + 1) {
		if (ans < sum) ans = sum;
		return;
	}
	if (day > n + 1) return;

	dobi_is_free(day + g[day], sum + h[day]);
	dobi_is_free(day + 1, sum);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g[i] >> h[i];
	}
	dobi_is_free(1, 0);
	cout << ans << '\n';
	return 0;
}