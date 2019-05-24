#include<stdio.h>

int sel_min(int arr[][5]) {
	int min = 0; 
	int miX = 0, minY = 0;

	min = arr[0][0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
				minX = i; minY = j;
			}

			arr[minX][minY] = 26;
			return min;
		}
	}
}

int main() {
	int arr[][5] = {
		{ 9,20,2,18,11 },
		{ 19,1,25,3,21 },
		{ 8,24,10,17,7 },
		{ 15,4,16,5,6 },
		{ 12,13,22,23,14 }
	};
	int sorted_arr[5][5] = { 0 };
	int cur_min = -1;
	int X, Y;
	int newX = 0, newY = 0;
	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };
	int dir_stat = 0;
	for (int i = 0; i < 25; i++) {
		cur_min = sel_min(arr);
		X = newX; Y = newY;
		sorted_arr[Y][X] = cur_min;
		newX = X + dx[dir_stat];
		newY = Y + dy[dir_stat];
		if (sorted_arr[newY][newX] != 0 || newY > 4 || newX > 4) {
			dir_stat = (dir_stat + 1) % 4;
			newX = X + dx[dir_stat];
			newY = Y + dy[dir_stat];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%3d", sorted_arr[i][j]);
		printf("\n");
	}

	return 0;
}
