#include<stdio.h>

int array[8][8] = {0, };
int visited[8] = {0, };

void backtracking(int v) {
	printf("%d ", v);
	visited[v] = 1; 
	
	for(int i = 1; i <= 7; i++) { 
		if(visited[i] == 0 && array[v][i] == 1) {
			backtracking(i);
		}
	}
}



int main() {
		 int a, b; 
		 for( int i = 0; i < 7; i++) {
		 		scanf("%d %d", &a, &b);
		 		array[a][b] = 1;
		 		array[b][a] = 1; 
		 }
		 
		 backtracking(1);
	return 0;
}
