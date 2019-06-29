#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	ī�� �����ϱ� 
	https://www.acmicpc.net/problem/11052
	
	ī�� N���� �����ؾ� �Ѵ�.
	ī������ �� N���� ������ �����Ѵ�.
	i��° ī������ i���� ī�带 ��� �ְ�, ������ P[i]���̴�.
	ī�� N���� �����ϴ� ����� �ִ밪�� ���ϴ� ����
	D[i] = ī�� i�� �����ϴ� �ִ� ���
	ī�� i���� �����ϴ� �����?

	ī�� 1���� ����ִ� ī������ �����ϰ�, ī�� i - 1���� ����
	P[1] + D[ i -1]
	ī�� 2���� ����ִ� ī������ �����ϰ�, ī�� i - 2���� ����
	P[2] + D[ i -2]
	��.
	ī�� i - 1���� ����ִ� ī������ �����ϰ�, ī�� 1���� ����
	P[i-1] + D[1]
	ī�� i���� ����ִ� ī������ �����ϰ�, ī�� 0���� ����
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
