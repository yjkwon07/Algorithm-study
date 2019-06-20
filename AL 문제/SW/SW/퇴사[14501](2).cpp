#include<stdio.h>
#include<algorithm>
using namespace std;
/*
	퇴사 
	https://www.acmicpc.net/problem/14501
	
	na982
	문제 설명

	N이 작기 때문에 dfs도 가능해 보입니다.
	어떻게 풀어도 상관없지만 가능하다면 쉽고 빠르게 풀 수 있는
	DP 방식으로 풀도록 하겠습니다.

	DP[day] = max(DP[day + 1], DP[day + T[day]] + P[day])

	day 에서 시작해서 퇴사일 까지 최대 값을 DP[day]에 저장합니다.
	DP[day]는 두 가지 중에 최대값을 저장하면 됩니다.
	- 오늘의 스케줄을 하는 경우: DP[day + T[day] ] + P[day]
	- 오늘의 스케줄을 안 하는 경우: DP[day + 1]
*/

int n;
int T[15], P[15];
int cache[15];

int solve(int day) {
	if (day > n) return -987654321;
	if (day == n) return 0;

	int &ret = cache[day];
	if (ret != -1) return ret;

	ret = max(solve(day + 1), solve(day + T[day]) + P[day] );
	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &T[i], &P[i]);
		cache[i] = -1;
	}
	int ret = solve(0);
	printf("%d\n", ret);
	return 0;
}
