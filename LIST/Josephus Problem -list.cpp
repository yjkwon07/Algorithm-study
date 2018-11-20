#include <stdio.h>
#include <malloc.h>

struct NODE {
	int index;
	NODE * link;
};

int main() {
	int N,K,i,j;
	NODE * delete_node; 
	NODE * first = (NODE *)malloc(sizeof(NODE));
	NODE * node = first;
	
	scanf("%d%d", &N, &K);
	
	// 첫번째 노드 생성
	node -> index = 1;
	
	for(i = 2; i <= N; i++) {
		node -> link = (NODE*)malloc(sizeof(NODE));
		node = node -> link;
		node -> index = i;
	}
	
	// 마지막 노드와 첫 노드를 연결해준다. 
	node -> link = first;
	node = node -> link;
	
	for (i = 0; i < N -1; i++) {
		// node를 K - 1만큼 이동시킨다. 
		for (j =1; j < K; j++)  {
			node = node -> link;
		}
		
		//node의 다음 노드를 지운다.
		delete_node = node -> link;
		node -> link = delete_node -> link;
		
		free(delete_node);
		
		node = node -> link; 
	} 
	
	printf("%d\n", node -> index );
	return 0;
}
