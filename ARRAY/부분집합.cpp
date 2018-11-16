// 부분 집합 생성 

#include <stdio.h> 

int main(void) {
	int i , j, k ,l;
	int element[4];
	for (int i =0; i <= 1; i++){
		element[0] = i;
		for ( int j = 0; j <= 1; j++){
			element[1] =j;
			for(int k =0; k <= 1; k++) {
				element[2] = k;
				for(int l=0; l <= 1; l++) {
					element[3] = l;
					// 원소 출력 
					printf("%d%d%d%d\n",element[0],element[1],element[2],element[3]); 
				}
			}
		}
	}
}
