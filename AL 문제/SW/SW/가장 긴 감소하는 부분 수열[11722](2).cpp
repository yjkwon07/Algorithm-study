#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	���� �� �����ϴ� �κ� ����
	https://www.acmicpc.net/problem/11722
	���� A�� �־����� ��, �� ������ �����ϴ� �κ� ���� �߿��� ���� �� ���� ���ϴ� ����

	�� ���� ����� �ִ�.
	�Է����� �־��� ���� A�� ����� ���� �� �����ϴ� �κ� ������ ���ϴ� ���
	���� �� �����ϴ� �κ� ������ ����ϰ� ���ϴ� ��� (�ڿ������� ���ؾ� �Ѵ�.)
	D[i] = A[i]���� �����ϴ� ���� �� �����ϴ� �κ� ������ ����
	D[i] = max(D[j]) + 1 ( i < j && A[i] > A[j])

*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	for (int i = n - 1; i >= 0; i--) {
		b[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && b[i] < b[j] + 1) { 
				b[i] = b[j] + 1;
			}
		}
	}
	cout << *max_element(b.begin(), b.end()) << '\n';
	cin >> n;
	return 0;
}