#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	카드 구매하기 2 
	https://www.acmicpc.net/problem/16194

	카드 N개를 구매해야 한다.
	카드팩은 총 N가지 종류가 존재한다.
	i번째 카드팩은 i개의 카드를 담고 있고, 가격은  P[i]원이다.
	카드 N개를 구매하는 비용의 최솟값을 구하는 문제 
	D[i] = 카드 i개 구매하는 최소 비용 
	카드 i개를 구매하는 방법은?
	카드 j개가 들어있는 카드팩을 구매하고, 카드 i - j개를 구매
	D[i] = min(D[i], P[j] + D[ i - j ] ) ( 1 <= j < i )
	이 방법은 배열 d에 항상 0이 들어간다.
	카드를 구매하는 비용은 0보다 크기 때문에, min의 결과는 항상 0이다.
	따라서, 배열의 초기값을 잘 설정해야 한다.
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++)
		d[i] = 1000 * 10000;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], a[j] + d[i - j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}
/*
		int main() {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<int> d(n + 1, -1);
		d[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (d[i] == -1 || d[i] > d[i - j] + a[j]) {
					d[i] = d[i - j] + a[j];
				}
			}
		}
		cout << d[n] << '\n';
		return 0;
	}
*/