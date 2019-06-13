#include<cstdio>
#include<queue>
/*
	파이프 옮기기 
	https://www.acmicpc.net/problem/17070

	DFS 
	경우의 수 if 분기문으로 조절 
*/
int N;
int arr[20][20];
int ans;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void go(int x, int y, int flag) {
	if (x == N && y == N) {
		ans += 1;
	}
	
	if (flag == 0) {
		if (y + 1 <= N) {
			if(arr[x][y + 1] == 0)
				go(x, y + 1, 0);
		}

		if (x + 1 <= N && y + 1 <= N) {
			if (arr[x + 1][y + 1] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y] == 0)
				go(x + 1, y + 1, 2);
		}
	}
	
	else if (flag == 1) {

		if (x + 1 <= N) {
			if (arr[x + 1][y] != 1)
				go(x + 1, y, 1);
		}
		
		if (x + 1 <= N && y + 1 <= N) {
			if (arr[x + 1][y + 1] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y] == 0)
				go(x + 1, y + 1, 2);
		}

	}
	
	else {
		if (y + 1 <= N) {
			if (arr[x][y + 1] != 1)
				go(x, y + 1, 0);
		}
		if (x + 1 <= N) {
			if (arr[x + 1][y] != 1)
				go(x + 1, y, 1);
		}
		if (x + 1 <= N && y + 1 <= N) {
			if (arr[x + 1][y + 1] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y] == 0)
				go(x + 1, y + 1, 2);
		}
	}
}

int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	go(1, 2, 0);
	printf("%d\n", ans);
	return 0;
}