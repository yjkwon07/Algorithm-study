#include<iostream>
using namespace std;
/*
	O(n)
	1로 만들기
	https://www.acmicpc.net/problem/1463
	=> 모든 경우의 수 
	=> X
	X = [X - 1]( X - 1)로 만들 수 있는 경우의 수 + 1
	X = [X / 3]( X / 3)로 만들 수 있는 경우의 수 + 1
	X = [X / 2]( X / 2)로 만들 수 있는 경우의 수 + 1

	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지
	X가 3으로 나누어 떨어지면, 3으로 나눈다.
	X가 2로 나누어 떨어지면, 2로 나눈다.
	1을 뺀다.

	어떤 정수 N에 위와 같은 연산을 선택해서 1을 만들려고 한다.
	연산을 사용하는 횟수의 최솟값을 구하는 문제
	N을 1로 만들려고 한다.
	N을 작게 만들어야한다.
	3으로 나누는 것이 수를 빠르게 작게 만든다.

	3으로 나누는 것, 2로 나누는 것, 1을 빼는 우선 순위로 N을 1로 만들어 본다.
	이 방법은 정답을 구 할 수 없다. (반례 10)
*/
int d[1000000];
// 탑 다운
int go(int x) {
	if (x == 1) return 0;
	if (d[x] > 0) return d[x];
	d[x] = go(x - 1) + 1;
	if (x % 3 == 0) {
		int temp = go(x / 3) + 1;
		if (d[x] > temp) d[x] = temp;
	}
	if (x % 2 == 0) {
		int temp = go(x / 2) + 1;
		if (d[x] > temp) d[x] = temp;
	}
	return d[x];
}

// 바텀 업
int go2(int n) {
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 & d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	return d[n];
}

int main() {
	int n;
	cin >> n;
	cout << go(n);

}