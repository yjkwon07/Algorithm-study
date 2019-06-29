#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	ī�� �����ϱ� 2 
	https://www.acmicpc.net/problem/16194

	ī�� N���� �����ؾ� �Ѵ�.
	ī������ �� N���� ������ �����Ѵ�.
	i��° ī������ i���� ī�带 ��� �ְ�, ������  P[i]���̴�.
	ī�� N���� �����ϴ� ����� �ּڰ��� ���ϴ� ���� 
	D[i] = ī�� i�� �����ϴ� �ּ� ��� 
	ī�� i���� �����ϴ� �����?
	ī�� j���� ����ִ� ī������ �����ϰ�, ī�� i - j���� ����
	D[i] = min(D[i], P[j] + D[ i - j ] ) ( 1 <= j < i )
	�� ����� �迭 d�� �׻� 0�� ����.
	ī�带 �����ϴ� ����� 0���� ũ�� ������, min�� ����� �׻� 0�̴�.
	����, �迭�� �ʱⰪ�� �� �����ؾ� �Ѵ�.
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