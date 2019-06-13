#include <cstdio>
#include <cstring>
/*
	미세먼지 안녕 
	https://www.acmicpc.net/problem/17144
	dfs -> memcpy -> original , (After, effective_action)
	미세먼지 이동하기
	빈 칸 라인 부터 옮기는 것이 편했음 

	O(n^2)

*/

int R, C, T; 
int dust_arr[50][50];
int dust_arr_copy[50][50];

struct AIR {
	int air1_x;
	int air2_x;
};

struct DUST
{
	int x, y;
};

AIR air = { -1, -1};
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void dust_attack() {
	int b[50][50] = { 0 };
	memcpy(b, dust_arr, sizeof(dust_arr));
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<C; j++) {
			if (dust_arr[i][j] >= 5) {
				int d = dust_arr[i][j] / 5;
				for (int k = 0; k<4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (0 <= ni && ni < R && 0 <= nj && nj < C 
						&& dust_arr[ni][nj] != -1) {
						b[ni][nj] += d;
						b[i][j] -= d;
					}
				}
			}
		}
	}
	memcpy(dust_arr, b, sizeof(b));
}

// 반시계
void front() {
	for (int i = air.air1_x - 2; i >= 0; i--) dust_arr[i + 1][0] = dust_arr[i][0];  // ↓
	for (int i = 0; i<C - 1; i++) dust_arr[0][i] = dust_arr[0][i + 1];    // ←
	for (int i = 0; i<air.air1_x; i++) dust_arr[i][C - 1] = dust_arr[i + 1][C - 1]; // ↑
	for (int i = C - 2; i >= 0; i--) dust_arr[air.air1_x][i + 1] = dust_arr[air.air1_x][i]; // →
	dust_arr[air.air1_x][1] = 0;
}

// 시계
void back() {
	// Bottom purifier
	for (int i = air.air2_x + 1; i<R - 1; i++) dust_arr[i][0] = dust_arr[i + 1][0];   // ↑
	for (int i = 0; i<C - 1; i++) dust_arr[R - 1][i] = dust_arr[R - 1][i + 1];  // ←
	for (int i = R - 2; i >= air.air2_x; i--) dust_arr[i + 1][C - 1] = dust_arr[i][C - 1];// ↓
	for (int i = C - 2; i >= 0; i--) dust_arr[air.air2_x][i + 1] = dust_arr[air.air2_x][i];   // →
	dust_arr[air.air2_x][1] = 0;
}

void air_refresh() {
	front();
	back();
}

void ans() {
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(dust_arr[i][j] >0){
				ans += dust_arr[i][j];
			}
		}
	}
	printf("%d\n", ans);
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", dust_arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	// init
	scanf_s("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf_s("%d",&dust_arr[i][j]);
			if (dust_arr[i][j] == -1) {
				if (air.air1_x == -1) {
					air.air1_x = i;
				}
				else {
					air.air2_x = i;
				}
			}
		}
	}
	while (T--)
	{
		dust_attack();
		air_refresh();
	}
	ans();
	return 0;
}