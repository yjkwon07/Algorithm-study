/*
�ʺ� �켱 Ž�� �������� ������ �������� ���� ��� ���ʷ� �湮�� �Ŀ�,
�湮�ߴ� ������ ���������� �Ͽ� �ٽ� ������ �������� ���ʷ� �湮�ϴ� ����̴�.
����, ������ �����鿡 ���� Ž���� �� ��, ���ʷ� �ٽ� �ʺ� �켱 Ž���� �����ؾ� �ϱ� ������,
���Լ��� ������ �ڷᱸ���� ť�� Ȱ���ϴ� ��� ���� ������ �����ϴ�. 

���� �켱 Ž�������� �湮�ϴ� ������ ���ÿ� �־�ξ�, �ǵ��ư� ������ ǥ���� �ξ���.
�ʺ� � Ž�������� ť�� �̿��Ͽ� ������ �湮�� ������ ǥ�� �Ѵ�.
enQueue�� ������ �湮�� ������ ����ϴ� �ǹ̷� ���ǰ�, dequeue�� ������ �湮�ϴ� ���� �ǹ��Ѵ�.
 
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

int n;// ������ ���� 
int m; // ������ ����
int i, j; 
int a, b; // �ԷµǴ� �� ����

int adjacent[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT]; // �������� ������ �Ǿ� �ִ��� �ľ�
int visited[MAX_VERTEX_COUNT]; // �� ��忡 �湮 �ߴ����� ���� ���� 
int visitedVertex; // ���� ���ϴ� ������ �ε���, ������ ������ ã�µ� ��� �ȴ�. 


int main() {

	scanf("%d", &t);
	
	while(t--) {
		//�ʱ�ȭ
		for(i = 1; i <= n; i++) {
			visited[i] =NOT_VISITED;
			for(j =1; j <= n; j++) {
				adjacent[i][j] = FALSE;
			}
		}
		
		scanf("%d%d", &n, &m);
		
		// �� ������ �־����� �� ������ ������ �Ǿ� �ִ� ������ ǥ��
		for(i =0; i < m; i++) {
			scanf("%d%d", &a, &b);
			adjacent[a][b] = TRUE;
			adjacent[b][a] = TRUE;
		}	
		
		// ť ����
		createQueue();
		
		// ù �������� ����1�� ť�� �ְ�, �湮�Ѱ����� ǥ�� 
		enQueue(1);
		visited[1] = IS_VISITED;
		 
		 while( isEmpty() == FALSE) {
		 	visitedVertex = deQueue();
		 	printf("%d ", visitedVertex);
		 	// ������ ������ ã�´�. 
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

	
