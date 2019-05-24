#include <stdio.h>

/*
5×5의 2차 배열에 무작위로 25개의 숫자로 초기화를 한 후 25개의 각 요소에 대해서 
그 요소와 이웃한 요소와의 차의 절대값을 구한 뒤, 구한모든값의총합을구한다. 
예를 들어 아래 그림에서 7이 이웃한 값은 2,  6,  8,  12 이며 차의 절대값은 12이다. 
(|2–7|+|8–7|+|12–7|+|6–7|=12)
*/

bool isWall(int x, int y){
	if( x < 0 || x >= 5) return true;
	if( y < 0 || y >= 5) return true;
	return false;
}

int calAbs(int a1, int a2) {
	return (a1 - a2) > 0 ? (a1 - a2) : -(a1 - a2);
}

void main() {
	int ary[][5] = {
		{9 , 20 , 2, 18 ,11},
		{19, 1, 25, 3, 21},
		{8, 24, 10, 17, 7},
		{15, 4, 16, 5, 6},
		{12, 13, 22, 23, 14}
	};
	
	int dx[] = { 0, 0, -1, 1}; // 상하좌우
	int dy[] = {-1, 1, 0, 0};
	int newX, newY;
	int sum = 0;
	
	for(int y =0; y <5; y++){
		for(int x =0; x < 5; x++) {
			for(int dir = 0; dir < 4; dir++) {
				newX = x + dx[dir];
				newY = y + dy[dir];
				if(!isWal(newX, newY)) 
					sum += calAbs(ary[y][x], ary[newY][newX]);
			}
		}
	}
	
	printf("sum = %d\n", sum);
}
