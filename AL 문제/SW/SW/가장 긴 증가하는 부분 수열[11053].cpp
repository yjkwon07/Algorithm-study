#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
	���� �� �����ϴ� �κ� ���� 
	https://www.acmicpc.net/problem/11053
	
	LIS(Longest Increasing subsequence)
	���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ����
	����
	���� A = 10, 20, 10, 30, 20, 50 ( ���Ƿ� ������ ������  �κ� �����̶�� �Ѵ�)
	���� �� �����ϴ� �κ� ���� A = { 10, 20, 10, 30, 20 ,50}
	{10, 20, 30, 50}
	ũ�Ⱑ N�� ��, �κм����� ũ��� 2^N
	N <= 1000
	���ϰ� ū �� �θ�Ʈ ������ Ǯ �� ���� ���� (2^1000)
	�� ������ ���̳������� �ذ� �� �� �ִ�.
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