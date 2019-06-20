#include<iostream>
#include<vector>
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
*/
vector<int> a;
int arr[3] = { 1, 2 ,3 };
int ans;
int counts;
void go(int total) {
	// 총 합 조건
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