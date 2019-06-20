#include<iostream>
using namespace std;
/*
	날짜 계산
	https://www.acmicpc.net/problem/1476

	가능한 경우의 수
	15 * 28  * 19 = 7980
	모든 경우를 다 해보면 된다
	year mod 15 == E
	year mod 28 == S
	year mod 19 == M
	이런식으로 year를 0부터 증가시키면서 위의 식을 검사해 
	구현하는 방법도 가능하다.
*/
int main() {
	int E, S, M;
	cin >> E >> S >> M;
	
	E--;
	S--;
	M--;

	int t = 0;
	for (; ; t++) {
		if ((t % 15  == E) && (t % 28 == S) && (t % 19 == M)) break;
	}
	cout << t + 1 << '\n';
	return 0;
}