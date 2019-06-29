#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	���� ū ���� �κ� ���� 
	https://www.acmicpc.net/problem/11055

	���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���� 

	D[i] = A[1], ...A[i] ���� ������ ���� ��, A[i]�� ���������� �ϴ� ���� ū �����ϴ� �κ� ������ ����
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && b[i] < b[j] + a[i]) {
				b[i] = b[j] + a[i];
			}
		}
	}
	cout << *max_element(b.begin(), b.end()) << '\n';
	return 0;
}