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
	
	// ù��° ��� ����
	node -> index = 1;
	
	for(i = 2; i <= N; i++) {
		node -> link = (NODE*)malloc(sizeof(NODE));
		node = node -> link;
		node -> index = i;
	}
	
	// ������ ���� ù ��带 �������ش�. 
	node -> link = first;
	node = node -> link;
	
	for (i = 0; i < N -1; i++) {
		// node�� K - 1��ŭ �̵���Ų��. 
		for (j =1; j < K; j++)  {
			node = node -> link;
		}
		
		//node�� ���� ��带 �����.
		delete_node = node -> link;
		node -> link = delete_node -> link;
		
		free(delete_node);
		
		node = node -> link; 
	} 
	
	printf("%d\n", node -> index );
	return 0;
}
