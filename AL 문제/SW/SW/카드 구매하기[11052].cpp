#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	카드 구매하기 
	https://www.acmicpc.net/problem/11052
	
	카드 N개를 구매해야 한다.
	카드팩은 총 N가지 종류가 존재한다.
	i번째 카드팩은 i개의 카드를 담고 있고, 가격은 P[i]원이다.
	카드 N개를 구매하는 비용의 최대값을 구하는 문제
	D[i] = 카드 i개 구매하는 최대 비용
	카드 i개를 구매하는 방법은?

	카드 1개가 들어있는 카드팩을 구매하고, 카드 i - 1개를 구매
	P[1] + D[ i -1]
	카드 2개가 들어있는 카드팩을 구매하고, 카드 i - 2개를 구매
	P[2] + D[ i -2]
	….
	카드 i - 1개가 들어있는 카드팩을 구매하고, 카드 1개를 구매
	P[i-1] + D[1]
	카드 i개가 들어있는 카드팩을 구매하고, 카드 0개를 구매
	P[i] + D[0]

	D[i] = max(D[i], P[j] + D[i-j]) ( 1 <= j <= i)
	N * O(N) = O(N^2)
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], a[j] + d[i - j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}
