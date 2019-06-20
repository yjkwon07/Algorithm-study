#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	부분수열의 합
	https://www.acmicpc.net/problem/1182

	모든 집합의 개수 = 2^N
	모든 집합을 구해보면 된다.
	전체집합 = (1<<N) -1
	공집합은 제외해야 한다.
	집합에 무엇이 포함되어 있는지 확인하기
	O(N * 2^n)
*/
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i &(1 << j)) {
				sum += a[j];
			}
		}
		if (sum == m) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}