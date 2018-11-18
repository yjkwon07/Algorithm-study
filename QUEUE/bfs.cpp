/*
너비 우선 탐색 시작점의 인접한 정점들을 먼저 모두 차례로 방문한 후에,
방문했던 정점을 시작점으로 하여 다시 인접한 정점들을 차례로 방문하는 방식이다.
따라서, 인접한 정점들에 대해 탐색을 한 후, 차례로 다시 너비 우선 탐색을 진해해야 하기 때문에,
선입선출 형태의 자료구조인 큐를 활용하는 경우 쉽게 구현이 가능하다. 

깊이 우선 탐색에서는 방문하는 정점을 스택에 넣어두어, 되돌아갈 정점을 표시해 두었다.
너비 운선 탐색에서는 큐를 이용하여 앞으로 방문할 정점을 표시 한다.
enQueue는 앞으로 방문할 정점을 등록하는 의미로 사용되고, dequeue는 정점에 방문하는 것을 의미한다.
 
*/

#include <stdio.h> 
#define QUEUE_SIZE 10001
#define MAX_VERTEX_COUNT 10001

#define TRUE 1
#define FALSE 0

#define IS_VISITED 1
#define NOT_VISITED 0

int queue[QUEUE_SIZE];
int front;
int rear;

int isEmpty() {
  if(front == rear)
    return true;
  else 
    return false;
}

int isFull() { 
  if(rear == MAX_VERTEX_COUNT-1)
    return true;
  else return false;
}

void enQueue(int item){
  if(isFull()) 
    return;
  else {
    rear = rear +1;
    queue[rear] = item;
  }
}

int deQueue() {
  if(isEmpty()) 
    return 0;
  else {
    front = front+1;
    return queue[front];
  }
} 

void createQueue() {
	queue[QUEUE_SIZE] = {0, };
	front = -1;
	rear = -1;
}

int t;

int n;// 정점의 개수 
int m; // 간선의 개수
int i, j; 
int a, b; // 입력되는 두 정점

int adjacent[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT]; // 정점들이 연결이 되어 있는지 파악
int visited[MAX_VERTEX_COUNT]; // 각 노드에 방문 했는지에 대한 정보 
int visitedVertex; // 현재 방하는 정점의 인덱스, 인접한 정점을 찾는데 사용 된다. 


int main() {

	scanf("%d", &t);
	
	while(t--) {
		//초기화
		for(i = 1; i <= n; i++) {
			visited[i] =NOT_VISITED;
			for(j =1; j <= n; j++) {
				adjacent[i][j] = FALSE;
			}
		}
		
		scanf("%d%d", &n, &m);
		
		// 두 정점이 주어지면 두 정점을 연결이 되어 있는 것으로 표시
		for(i =0; i < m; i++) {
			scanf("%d%d", &a, &b);
			adjacent[a][b] = TRUE;
			adjacent[b][a] = TRUE;
		}	
		
		// 큐 생성
		createQueue();
		
		// 첫 시작점인 정점1을 큐에 넣고, 방문한것으로 표시 
		enQueue(1);
		visited[1] = IS_VISITED;
		 
		 while( isEmpty() == FALSE) {
		 	visitedVertex = deQueue();
		 	printf("%d ", visitedVertex);
		 	// 인접한 정점을 찾는다. 
			for( i = 1; i <=n; i++) { 
				if(adjacent[visitedVertex][i] == TRUE && visited[i] == FALSE) { 
					enQueue(i);
					visited[i] = IS_VISITED;
				}
			}
		 }
		 printf("\n");
	}
	

}

	
