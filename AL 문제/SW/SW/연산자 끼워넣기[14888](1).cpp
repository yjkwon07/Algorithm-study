#include<stdio.h>
using namespace std;
/*
	연산자 끼워넣기
	https://www.acmicpc.net/problem/14888

	na982
	문제 설명

	숫자는 고정이고, 연산자의 순서만 변경 될 수 있는 문제 입니다.
	연산자의 종류는 총 4개 (더하기, 빼기, 곱하기, 나누기)입니다.
	연산자의 종류가 같다면, 순서는 상관없지만,
	연산자의 종류가 다르다면, 순서는 상관이 있습니다.
	위의 경우를 잘 생각해서 모든 경우를 다 만들어 보고 최대 값과 최소 값을 구하면 되는 문제 입니다.

	연산자의 우선순위가 무시되고, 앞에서 부터 순서대로 계산하는 간단한 문제 입니다.
	연산와 피연산자(숫자)가 두개 들어오면 그때 그때 계산하고 다음 단계로 넘기면 되는 문제 입니다.
	
	!!!op[]로 개수 체크를하여 무한 반복문을 제거한다.
*/
int n;
int number[11];
int op[4];
int ret_min = 0x7fffffff, ret_max = -ret_min;

void dfs(int result, int count) {
	if (count == n - 1) {
		if (ret_min > result) {
			ret_min = result;
		}
		if (ret_max < result) {
			ret_max = result;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i] -= 1;
			if (i == 0) {
				dfs(result + number[count + 1], count + 1);
			}
			else if (i == 1) {
				dfs(result - number[count + 1], count + 1);
			}
			else if (i == 2) {
				dfs(result * number[count + 1], count + 1);
			}
			else if (i == 3) {
				dfs(result / number[count + 1], count + 1);
			}
			op[i] += 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
	dfs(number[0], 0);
	printf("%d\n%d\n", ret_max, ret_min);
	return 0;
}