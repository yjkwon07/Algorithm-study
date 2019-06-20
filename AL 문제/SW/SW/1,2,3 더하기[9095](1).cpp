#include<iostream>
#include<vector>
using namespace std;
/*
	1,2,3 ���ϱ�
	https://www.acmicpc.net/problem/9095
	���� n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ����
	N�� 10���� �۰ų� ���� ������
	�ִ� 10�� ���Ϸ� ǥ�� ����
	10�� for��!!

	������ �׳� ������ Ǯ����.
	why? -> �ʹ� ���...
	���� �ݺ��� �����ϱ� ������ check�� ������� �ʾҴ�.
*/
vector<int> a;
int arr[3] = { 1, 2 ,3 };
int ans;
int counts;
void go(int total) {
	// �� �� ����
	if (total == ans) {
		counts++;
		return;
	}
	// back tracking
	if (total > ans) return;

	for (int i = 0; i < 3; i++) {
		go(total + arr[i]);
	}
	return;
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		counts = 0;
		cin >> ans;
		go(0);
		cout << counts << '\n';
	}
	cin >> n;
	return 0;
}