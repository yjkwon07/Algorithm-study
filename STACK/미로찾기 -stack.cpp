#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct
{
	int x, y;
} PAIR; 

int g_map[100][100];
char g_resultmap[100][100];
PAIR g_stack[10000];
int g_top;

int main() {
	int T; 
	int start_x, start_y, now_x, now_y;
	int is_findpath;
	int W, H, i, j;
	char str[101];
	
	scanf("%d", &T);
	while(T--){
		is_findpath = FALSE;
		g_top = 0; 
		
		scanf("%d%d", &W, &H);
		for(i =0; i <H; i++){
			scanf("%s", str);
			for(j = 0; j <W; j++) {
				if(str[j] =='2') {
					start_x = j;
					start_y = i;
				}
				g_map[i][j] = str[j] - '0';
			}
		}
		
		// 시작점 Push
		g_stack[g_top].x = start_x;
		g_stack[g_top].y = start_y;
		g_top++;
		
		while(g_top) {
			now_x = g_stack[g_top - 1].x; 
			now_y = g_stack[g_top -1].y;
			
			if(g_map[now_y][now_x] == 3) { // 도착 지점 인 경우
				is_findpath = TRUE;
				break; 
			}
			g_map[now_y][now_x] = 1;
			
			if(now_x > 0 && g_map[now_y][now_x - 1] != 1) { // Push
				g_stack[g_top].x = now_x - 1;
				g_stack[g_top].y = now_y;
				g_top++;
			}
			else if(now_x < W -1 && g_map[now_y][now_x +1] != 1) { // Push
				g_stack[g_top].x = now_x + 1;
				g_stack[g_top].y = now_y;
				g_top++; 
			}			
			else if(now_y > 0 && g_map[now_y-1][now_x] != 1) { // Push
				g_stack[g_top].x = now_x;
				g_stack[g_top].y = now_y - 1;
				g_top++; 
			}
			else if(now_y < H -1 && g_map[now_y+1][now_x] != 1) { // Push
				g_stack[g_top].x = now_x;
				g_stack[g_top].y = now_y + 1;
				g_top++; 
			}
			else { // 갈곳이 없는 경우 Pop
				g_top--; 
			}
		}
		
		if(is_findpath == FALSE) // 경로가 없는 경우
			printf("Can not Find Path.\n" );
			
		else {// 경로가 있는경우 
			for(i =0; i < H; i++)
				for(j =0; j < W; j++) 
					g_resultmap[i][j] = 'X';
					
			while(g_top) {
				 g_top--;
				 now_x = g_stack[g_top].x;
				 now_y = g_stack[g_top].y;
				 g_resultmap[now_y][now_x] = '.';
			} 
			
			for (i =0; i < H; i++) {
				for( j =0; j < W; j++) { 
					printf("%c", g_resultmap[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0; 
}	










































