#include <cstdio>
#include <cstring>

/*
	낚시왕 
	https://www.acmicpc.net/problem/17143
	1. 양식장 안에 shark 정보를 저장한다. 
	
	2. fish_killing, fish_killing_copy를 만들어 갱신한 물고기를 다시 
	memcpy를 통해 복사한다. 
	
	3. 나머지 정리로 이동 횟 수 줄이기!!. 벽에 닿으면 횟수가 인정되지 않기 때문에 
	spped % ( (R-1) *2 )
	
	O(n^2)
*/

struct SHARK {
	int r;
	int c;
	int speed;
	int dir;
	int size;
	bool live;
};

int R, C, M; 
int ans;
SHARK fish_killing[110][110]; // 양식장

void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%d ",fish_killing[i][j].live);
		}
		printf("\n");
	}
}

int main() {
	// 초기화
	scanf_s("%d %d %d", &R, &C, &M);
	
	for (int i = 0; i < M; i++) {
		SHARK shark;
		shark.live = true;
		scanf_s("%d %d %d %d %d", &shark.r, &shark.c, &shark.speed, &shark.dir, &shark.size);
		shark.dir -= 1;
		fish_killing[shark.r][shark.c] = shark; 
	}

	for (int c = 1; c <= C; c++) {
		SHARK fish_killing_copy[110][110] = { 0, };

		for (int r = 1; r <= R; r++) {
			// 1. 어부씨 공격하세요 
			if (fish_killing[r][c].live) {
				ans += fish_killing[r][c].size;
				fish_killing[r][c] = { 0, 0, 0, 0, 0, false };
				break;
			}
		}

		const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
		// Sharks move
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				
				if (fish_killing[i][j].live) {
					if (fish_killing[i][j].dir < 2) { // Up, Down
						int s = fish_killing[i][j].speed % ((R-1) * 2);
						int d = fish_killing[i][j].dir;
						int ni = i;
						while (s--) {
							if (ni == 1 && d == 0) d = 1;
							if (ni == R && d == 1) d = 0;
							ni += dx[d];
						}

						if (fish_killing[i][j].size > fish_killing_copy[ni][j].size) {
							fish_killing_copy[ni][j] = {
								fish_killing[i][j].r, fish_killing[i][j].c,
								fish_killing[i][j].speed, d, fish_killing[i][j].size, true
							};
						}
					}

					else { // Right, Left
						int s = fish_killing[i][j].speed % ((C-1) * 2);
						int d = fish_killing[i][j].dir;
						int nj = j;
						while (s--) {
							if (nj == 1 && d == 3) d = 2;
							if (nj == C && d == 2) d = 3;
							nj += dy[d];
						}
						if (fish_killing[i][j].size > fish_killing_copy[i][nj].size) {
							fish_killing_copy[i][nj] = {
								fish_killing[i][j].r, fish_killing[i][j].c,
								fish_killing[i][j].speed, d, fish_killing[i][j].size, true
							};
						}
					}
				}
			}
		}
		memcpy(fish_killing, fish_killing_copy,sizeof(fish_killing_copy));
	}

	printf("%d\n", ans);
	return 0;
}