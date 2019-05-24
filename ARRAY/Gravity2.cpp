#include<stdio.h>

#define EMTY 0
#define BOX 1

int main() {
	int i;
	int testCase, T;

	int roomWidth, roomHeight;
	int maxFallen;
	int room[100][100] = { EMTY, };
	int boxTop[100] = { 0, };
	int countEmtySpace;
	scanf("%d", &testCase);

	for (T = 0; T < testCase; T++) {
		scanf("%d%d", &roomWidth, &roomHeight);
		maxFallen = 0;
		for (i = 0; i < roomWidth; i++) // 방에 상자들을 채운다.
		{ 
			scanf("%d", &boxTop[i]);
			for (int j = 0; j < boxTop[i]; j++)
				room[i][j] = BOX;
		}

		// 각 상자 열(column)의 가장 위에 있는 상자의 낙차를 구한다.
		for (int i = 0; i < roomWidth; i++) {
			if (boxTop[i] > 0) {
				countEmtySpace = 0;
				
				for (int j = i + 1; j < roomWidth; j++) {
					// room[i][j]가 박스 일때 빈칸의 개수를 셈으로서 낙차를 구한다.
					if (room[j][boxTop[i] - 1] == EMTY) {
						countEmtySpace += 1;
					}
				}
				
				// 이전에 구한 낙차보다 현재 낙차가 크다면 업데이트 
				if (countEmtySpace > maxFallen) {
					maxFallen = countEmtySpace;
				}
			}
		}

		printf("%d\n", maxFallen);
	}
	return 0;
}