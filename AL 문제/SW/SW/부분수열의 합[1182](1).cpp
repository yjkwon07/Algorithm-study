#include<iostream>
#include<vector>
using namespace std;
/*
	부분수열의 합
	https://www.acmicpc.net/problem/1182

	서로 다른 N개의 정수로 이루어진 집합이 있을 때, 
	이 집합의 공집합이 아닌 부분집합 중에서 
	그집합의 원소를 다 더한값이 S가 되는 경우의 수를 구하는 문제
	1 <= N <= 20
	go(index, sum)
	index: 부분집합에 포함할지 말지 결정해야 하는 인덱스
	sum: 현재까지 부분집합의 합
*/
int go(vector<int> & a, int index, int m, int sum) {
	int ans = 0;
	int n = a.size();
	if (index == n) {
		if (sum == m) {
			return 1;
		}
		return 0;
	}
	ans += go(a, index + 1, m, sum + a[index]);
	ans += go(a, index + 1, m, sum);
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = go(a, 0, m, 0);
	if (m == 0) ans -= 1;
	cout << ans << '\n';
	cin >> n;
	return 0;
}