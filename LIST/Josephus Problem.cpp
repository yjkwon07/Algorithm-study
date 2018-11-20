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
			// �� k�� �����̵�, -1�� �̵� Ƚ���� ġ�� �ʴ´�.
			if (player[target] != -1) {
					move_count++;
			} 
		}
		// k�� �̵��� ���� plyaer�� -1�� �ٲ۴�. 
		player[target] = -1; 
		// �״��� ���ں��� �ٽ� ����� �ϹǷ�  
		
		// ���ʷ� �����ϴ� ���ڱ��� �̵��Ѵ�. 
		while( player[target] != -1) {
			target = (target + 1) % n; 
		}
	}
	printf("%d\n", target);
	printf("%d \n", player[target]);
	
	return 0;
}
