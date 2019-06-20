#include<iostream>
using namespace std;
/*
	1,2,3 더하기
	https://www.acmicpc.net/problem/9095
	정수 n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 문제
	N이 10보다 작거나 같기 때문에
	최대 10개 이하로 표현 가능
	10중 for문!!

	하지만 그냥 순열로 풀었다.
	why? -> 너무 길어...
	수가 반복도 가능하기 때문에 check는 사용하지 않았다.
	recursive의 기능을 알기 위해 sum+a[i]를 사용하여 모든게 이어지는지 
	확인
	=> 하나의 함수 콜로 시작하여서 다른 함수 콜에는 영향을 받지 않는다.
	=> 이걸로 많은 응용 가능할듯.
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