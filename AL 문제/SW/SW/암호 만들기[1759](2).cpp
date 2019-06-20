#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/*
	��ȣ �����
	https://www.acmicpc.net/problem/1759

	��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִ�.
	��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ���� �Ѵ�.
	��ȣ�� ����� �� �ִ� ������ ������ c����
	���ɼ� �ִ� ��ȣ�� ��� ���ϴ� ����
	start[]�迭�� selected ������ a�迭�� ��ġ ���� 
	�� ��� i�� ��ġ�� password ����
	so, index, selected delete!!!!!

	go(n, alpha, password, i)
		n: ������ �ϴ� ��ȣ�� ����
		alpha: ����� �� �ִ� ���ĺ�
		password: ������� ���� ��ȣ
		i: ������� ���� �����ؾ� �ϴ� ���ĺ��� �ε���
*/
bool check(string &password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}
void go(int n, vector<char> &alpha, string password, int i) {

	if (password.length() == n) {
		if (check(password)) {
			cout << password << '\n';
		}
		return;
	}

	if (i >= alpha.size()) return;
	go(n, alpha, password + alpha[i], i + 1);
	go(n, alpha, password, i + 1);
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	go(n, a, "", 0);
	return 0;
}