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
		for (i = 0; i < roomWidth; i++) // �濡 ���ڵ��� ä���.
		{ 
			scanf("%d", &boxTop[i]);
			for (int j = 0; j < boxTop[i]; j++)
				room[i][j] = BOX;
		}

		// �� ���� ��(column)�� ���� ���� �ִ� ������ ������ ���Ѵ�.
		for (int i = 0; i < roomWidth; i++) {
			if (boxTop[i] > 0) {
				countEmtySpace = 0;
				
				for (int j = i + 1; j < roomWidth; j++) {
					// room[i][j]�� �ڽ� �϶� ��ĭ�� ������ �����μ� ������ ���Ѵ�.
					if (room[j][boxTop[i] - 1] == EMTY) {
						countEmtySpace += 1;
					}
				}
				
				// ������ ���� �������� ���� ������ ũ�ٸ� ������Ʈ 
				if (countEmtySpace > maxFallen) {
					maxFallen = countEmtySpace;
				}
			}
		}

		printf("%d\n", maxFallen);
	}
	return 0;
}