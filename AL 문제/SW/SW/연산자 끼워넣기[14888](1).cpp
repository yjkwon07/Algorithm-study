#include<stdio.h>
using namespace std;
/*
	������ �����ֱ�
	https://www.acmicpc.net/problem/14888

	na982
	���� ����

	���ڴ� �����̰�, �������� ������ ���� �� �� �ִ� ���� �Դϴ�.
	�������� ������ �� 4�� (���ϱ�, ����, ���ϱ�, ������)�Դϴ�.
	�������� ������ ���ٸ�, ������ ���������,
	�������� ������ �ٸ��ٸ�, ������ ����� �ֽ��ϴ�.
	���� ��츦 �� �����ؼ� ��� ��츦 �� ����� ���� �ִ� ���� �ּ� ���� ���ϸ� �Ǵ� ���� �Դϴ�.

	�������� �켱������ ���õǰ�, �տ��� ���� ������� ����ϴ� ������ ���� �Դϴ�.
	����� �ǿ�����(����)�� �ΰ� ������ �׶� �׶� ����ϰ� ���� �ܰ�� �ѱ�� �Ǵ� ���� �Դϴ�.
	
	!!!op[]�� ���� üũ���Ͽ� ���� �ݺ����� �����Ѵ�.
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