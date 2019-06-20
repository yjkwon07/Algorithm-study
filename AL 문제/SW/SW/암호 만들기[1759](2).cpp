#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/*
	암호 만들기
	https://www.acmicpc.net/problem/1759

	암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다.
	암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었어야 한다.
	암호로 사용할 수 있는 문자의 종류는 c가지
	가능성 있는 암호를 모두 구하는 문제
	start[]배열은 selected 값으로 a배열의 위치 저장 
	그 대시 i의 위치로 password 갱신
	so, index, selected delete!!!!!

	go(n, alpha, password, i)
		n: 만들어야 하는 암호의 길이
		alpha: 사용할 수 있는 알파벳
		password: 현재까지 만든 암호
		i: 사용할지 말지 결정해야 하는 알파벳의 인덱스
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