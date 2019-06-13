#include<cstdio>
/*
	파이프 옮기기2
	https://www.acmicpc.net/problem/17069
	
	점화식 구하기 

*/
int N;
int p[40][40];
long long d[3][40][40];
long ans;

void go(int x, int y, int flag) {
	d[0][1][2] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!p[i][j + 1]) d[0][i][j + 1] += d[0][i][j] + d[2][i][j];
			if (!p[i + 1][j]) d[1][i + 1][j] += d[1][i][j] + d[2][i][j];
			if (!p[i + 1][j + 1] && !p[i + 1][j] && !p[i][j + 1]) {
				d[2][i + 1][j + 1] += d[0][i][j] + d[1][i][j] + d[2][i][j];
			}
		}
	}
	printf("%lld\n", d[0][N][N] + d[1][N][N] + d[2][N][N]);
}

int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &p[i][j]);
		}
	}
	go(1, 2, 0);
	scanf_s("%d", &ans);
	return 0;
}