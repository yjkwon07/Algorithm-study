#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
	가장 긴 증가하는 부분 수열 
	https://www.acmicpc.net/problem/11053
	
	LIS(Longest Increasing subsequence)
	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 문제
	예시
	수열 A = 10, 20, 10, 30, 20, 50 ( 임의로 선택한 수열을  부분 수열이라고 한다)
	가장 긴 증가하는 부분 수열 A = { 10, 20, 10, 30, 20 ,50}
	{10, 20, 30, 50}
	크기가 N일 때, 부분수열의 크기는 2^N
	N <= 1000
	어마어마하게 큰 수 부르트 포스는 풀 수 없는 문제 (2^1000)
	이 문제는 다이나믹으로 해결 할 수 있다.
	O(N^2)
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> d(n);
	for (int i = 0; i < n; i++) d[i] = 1;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
		if (temp < d[i]) temp = d[i];
	}

	cout << temp << '\n';
	return 0;
}