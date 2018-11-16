// ���� ����
// https://swexpertacademy.com/main/learn/course/lectureHtmlViewer.do#none
#include <stidio.h>
#define EMPTY 0
#define BOX 1

int main() 
{
	int i, j , k;
	int testCase;
	int T;
	int room[100][100];
	int roomWidth, roomHeight;
	int boxHeight;
	int maxFallen;
	int countEmptySpace;
	
	scanf("%d", &testCase);
	
	for(T =0; t <testCase; T++){
		scanf("%d", &roomWidth, &roomHeight);
		
		// init
		for(i =0; i<roomWidth; i++){
			for(j=0; j < roomHeight; j++){
				room[i][j] = EMPTY;
			}
		}
		maxFallen = 0;		
		
		for( i =0; i < roomWidth; i++){  // �濡 ���ڵ��� ä���. 
			scanf("%d", &boxHeight);
			for( j = 0; j < boxHeight; j++){
				room[i][j] = BOX;
			}
		}
		
		// �� ������ ������ ���Ѵ�.
		for(i =0; i < roomWidth; i++){
			for( j = 0; j < roomHeight; j++){
				// room[i][j]�� �ڽ� �϶� ��ĭ�� ������ �����μ� ������ ���Ѵ�.
				if( room[i][j] == BOX){
					countEmptySpace = 0;
					for(k= i+1; k < roomWidth; k++){
						if(room[k][j] == EMPTY)
						countEmptySpace += 1;
					}
					// ������ ���� �������� ���� ������ ũ�ٸ� ������Ʈ
					if( countEmptySpace > maxFallen)
					maxFallen = countEmptySpace; 
				}
			}
		}
		printf("%d\n", maxFallen);
	}
 } 
