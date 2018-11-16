#define MAX_MAZE_SIZE 100

#define IS_VISITED 1
#define NOT_VISITED 0

#define POSSIBLE_WAY 1 
#define IMPOSSIBLE_WAY 0

int testCase;
int w, h;

int maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // �̷� 
int visited[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // �� ĭ�� �湮 �ߴ����� ���� ���� 

int i, j;
char input[MAX_MAZE_SIZE] ;

int finePath(int x, int y) {
	int tempResult =0;
	
	if (maze[x][y] == 1 || visited[x][y] == IS_VISITED) // ���̰ų� �̹� �湮�ߴ� ���̸� �� �̻� �������� �ʴ´�.
		return IMPOSSIBLE_WAY;
	
	else if(maze[x][y] == 3) // �ⱸ�� ã�� ��� 
		return POSSIBLE_WAY;
		
	else // �� �� �ִ� ���̸� 4���⿡ ���ؼ� �� �� �մ��� �����Ѵ�. 
	{
		visited[x][y] = IS_VISITED; // ���� ��ġ�� ������ ��� ǥ���Ѵ�. 
		
		// 4���⿡ ���ؼ� �̵��� �� �ִ��� �Ǵ��Ѵ�. 
		tempResult += finePath(x-1, y) ;
		tempResult += finePath(x+1, y) ;
		tempResult += finePath(x, y-1) ;
		tempResult += finePath(x, y+1) ;		
		
		// �� ���ư� �� ������ ��� ǥ���ص� ���� ���� �Ѵ�. 
		visited[x][y] = NOT_VISITED;
		
		return tempResult;
	 } 
}

int main() {
	scanf("%d", &testCase);
	
	while (testCase--)
	{
		// �ʱ�ȭ 
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

	































