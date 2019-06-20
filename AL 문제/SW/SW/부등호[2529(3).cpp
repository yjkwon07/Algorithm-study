#include <iostream>
#include <string>
using namespace std;
/*
	부등호
	https://www.acmicpc.net/problem/2529
	알고리즘 분류 : 백트래킹

	기본적으로 재귀 함수를 이용하여 브루트 포스로 구현할 수 있다. 
	재귀 함수를 호출하기 전에 부등호 체크를 하는 방식으로 백트래킹을 하여 시간을 단축할 수 있다.

	하나의 숫자를 구하기 위해서 입력으로 주어진 길이(N)+1 만큼 재귀 함수를 호출해야 한다. 
	올바른 부등식은 숫자 개수가 부등호 개수보다 1개 더 많다.
	재귀 함수 종료 조건 : 숫자 개수(길이) == N+1
	수를 중복하여 사용할 수 없으므로, check 배열을 별도로 만들어서 사용 여부를 확인해야 한다.
	재귀 함수를 호출하기 전에, 다음 숫자가 부등식에 맞는지 살펴봐야 한다.
	예를 들어, 주어진 부등호가 < > > 라면, 0 < 3 > 2 > 1은 가능하다.
	하지만 3 < 2 > 1 > 0은 불가능하다. 이런 경우, 3 < 2부터 틀린 부등식이므로, 이 뒤로는 함수를 호출할 필요가 없다.
	재귀 함수 호출을 0부터 9까지 순서대로 부르므로, 정답의 최솟값은 처음 호출된 값이며, 최댓값은 마지막에 호출된 값이다.
*/
int n;
char op[9];
bool c[10];
string mn, mx;

bool possible(int i, int j, char k) {
	if (k == '<') return i < j;
	if (k == '>') return i > j;
	return true;
}

void solve(int cnt, string s) {
	if (cnt == n + 1) {
		if (!mn.size()) mn = s;
		else mx = s;
		return;
	}
	for (int i = 0; i<10; i++) {
		if (c[i]) continue;
		if (cnt == 0 || possible(s[cnt - 1], i + '0', op[cnt - 1])) {
			c[i] = true;
			solve(cnt + 1, s + to_string(i));
			c[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i<n; i++) cin >> op[i];
	solve(0, "");
	cout << mx << '\n';
	cout << mn << '\n';
	return 0;
}
