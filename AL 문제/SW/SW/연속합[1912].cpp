#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	연속합 
	https://www.acmicpc.net/problem/1912
	
	n개의 정수로 이루어진 임의의 수열이 주어진다.
	우리는 이 중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
	단, 숫자는 한 개 이상 선택해야 한다.
	예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1이라는 수열이 주어졌다고 하자.
	여기서 정답은 12+ 21인 33이 정답이 된다.
	D[i] = i번째 수로 끝나는 가장 큰 연속합
	이렇게 식을 구했으면, i번째 수에게 가능한 경우를 세어야 한다.
	i번째 수 에게 가능한 경우
	i -1번째 수의 연속합에 포함되는 경우
	D[i-1] + A[i]
	새로운 연속합을 시작하는 경우
	A[i]
	두 값 중에서 어떤 값이 D[i]에 들어가야 할까?(최대값)
	D[i] = max(D[i-1] + A[i], A[i])

*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i<n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int ans = d[0];
	for (int i = 1; i<n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;
}