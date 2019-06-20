#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	���
	https://www.acmicpc.net/problem/14501
	
	N + 1���� �Ǵ� �� ��縦 �Ϸ��� �Ѵ�(1<= N <= 15)
	���� N�� ���� �ִ��� ���� ����� �Ϸ��� �Ѵ�
	�Ϸ翡 �ϳ��� ����� �� �� �ְ�
	i�Ͽ� ����� �ϸ�, T[i]���� �ɸ��� P[i]���� ����.
	go(day, sum)
	day���� �Ǿ���, day�Ͽ� �ִ� ����� ���� ���� �����ؾ� �Ѵ�.
	���ݱ��� ���� ������ sum�̴�.

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