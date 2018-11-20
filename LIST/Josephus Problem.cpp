#include<stdio.h>

int player[1000000];

int main() {
	int n, k, move_count, target = 8;
	int i , j;
	
	scanf("%d %d", &n, &k);
	
	for(i = 0; i < n; i++){
		player[i] = i+1;
	}
	
	for(j =0; j < n -1; j++) {
		move_count = 0; 
		while(move_count < k) {
			target = (target + 1 ) % n;
			// 총 k번 움직이되, -1은 이동 횟수에 치지 않는다.
			if (player[target] != -1) {
					move_count++;
			} 
		}
		// k번 이동한 후인 plyaer를 -1로 바꾼다. 
		player[target] = -1; 
		// 그다음 숫자부터 다시 세어야 하므로  
		
		// 최초로 등장하는 숫자까지 이동한다. 
		while( player[target] != -1) {
			target = (target + 1) % n; 
		}
	}
	printf("%d\n", target);
	printf("%d \n", player[target]);
	
	return 0;
}
