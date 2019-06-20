#include<iostream>
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
	recursive�� ����� �˱� ���� sum+a[i]�� ����Ͽ� ���� �̾������� 
	Ȯ��
	=> �ϳ��� �Լ� �ݷ� �����Ͽ��� �ٸ� �Լ� �ݿ��� ������ ���� �ʴ´�.
	=> �̰ɷ� ���� ���� �����ҵ�.
*/
int a[3] = { 1, 2, 3 };
int ans;
void go(int sum, int goal) {
	if (sum == goal) {
		ans += 1;
		return;
	}
	if (sum > goal) return;
	for (int i = 0; i < 3; i++)
		go(sum + a[i], goal);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans = 0;
		int cnt;
		cin >> cnt;
		go(0, cnt);
		cout << ans << '\n';
	}
	return 0;
}