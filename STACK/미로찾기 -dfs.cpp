#define MAX_MAZE_SIZE 100

#define IS_VISITED 1
#define NOT_VISITED 0

#define POSSIBLE_WAY 1 
#define IMPOSSIBLE_WAY 0

int testCase;
int w, h;

int maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // 미로 
int visited[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // 각 칸에 방문 했는지에 대한 정보 

int i, j;
char input[MAX_MAZE_SIZE] ;

int finePath(int x, int y) {
	int tempResult =0;
	
	if (maze[x][y] == 1 || visited[x][y] == IS_VISITED) // 벽이거나 이미 방문했던 곳이면 더 이상 진행하지 않는다.
		return IMPOSSIBLE_WAY;
	
	else if(maze[x][y] == 3) // 출구를 찾은 경우 
		return POSSIBLE_WAY;
		
	else // 갈 수 있는 길이면 4방향에 대해서 갈 수 잇는지 조사한다. 
	{
		visited[x][y] = IS_VISITED; // 현재 위치를 지나온 길로 표시한다. 
		
		// 4방향에 대해서 이동할 수 있는지 판단한다. 
		tempResult += finePath(x-1, y) ;
		tempResult += finePath(x+1, y) ;
		tempResult += finePath(x, y-1) ;
		tempResult += finePath(x, y+1) ;		
		
		// 되 돌아갈 때 지나온 길로 표시해둔 것을 해제 한다. 
		visited[x][y] = NOT_VISITED;
		
		return tempResult;
	 } 
}

int main() {
	scanf("%d", &testCase);
	
	while (testCase--)
	{
		// 초기화 
		for (i = 0; i < MAX_MAZE_SIZE; i++) { 
			for( j = 0; j < MAX_MAZE_SIZE; j++) {
				maze[i][j] = 1;
				visited[i][j] = NOT_VISITED;
			}
		}
		scanf("%d%d", &w, &h);
		
		for(i =0; i < h; i++) {
			scanf("%s", input);
			for (j =0; j < w; j++) {
				maze[i][j] = input[j] - '0';
			}
		}
		
		if(finePath(1, 1) > 0)
			printf("1\n");
		else
			printf("0\n");
	}
}

	































