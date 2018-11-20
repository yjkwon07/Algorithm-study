#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

struct NODE {
  int data; 
  NODE *link;
};

void add_node(NODE * prev, NODE * p_new) {
  // 삽입될 위치의 바로 앞에 위치한 노드의 링크 필드를 p_new의 링크 필드에 복사 
  p_new -> link = prev -> link;
  
  // p_new의 주소를 앞 노드의 링크 필드에 저장
  prev -> link = p_new; 
}

NODE * delete_node(NODE *prev) {
  // 삭제할 노드의 앞 노드(선형 노드) 탐색 
  NODE * target_node = prev ->  link;
  
  // 삭제할 노드의 링크 필드를 선행 노드의 링크 필드에 복사 
  prev -> link = target_node -> link;
  
  // 더이상 접근 방법 없어진 target_node 리턴 
  target_node -> link = NULL;
  return target_node;
}

void InsetionSort(int data[], int size) {
  int i;
  // 정렬되지 않은 집합(head)에 기존 데이터를 대입한다. 
  NODE *head_unsorted = (NODE *)malloc(sizeof(NODE)); // 정렬되지 않은 집합 생성 (head)
  NODE *head_sorted = (NODE *)malloc(sizeof(NODE)); // 정렬된 집합 생성 (head)
  NODE *node = head_unsorted;
  NODE *prev, *curr; 
  
  head_unsorted -> link = NULL;
  head_sorted -> link = NULL;
  
  for(i = 0; i < size; i++) {
    node ->  link = (NODE *)malloc(sizeof(NODE));
    node = node -> link; 
    node -> data = data[i];
    node -> link = NULL;
  }
  
  // 정렬되지 않은 집합이 공집합이 될때 까지 
  while (head_unsorted -> link) {
    // 정렬되지 않은 집합의 첫번째 원소를 빼내어 
    node = delete_node(head_unsorted);
    
    // 정렬된 집합에서 자신보다 큰 원소앞에 넣는다.
    prev = head_sorted;
    curr = head_sorted -> link;
    while( curr && curr -> data < node -> data) {
      prev = prev -> link;
      curr = curr -> link; 
    }
    add_node(prev, node);
  }
  free(head_unsorted);
  // 다시 정렬된 집합의 내용을 data 배열에 저장 
  node = head_sorted -> link;
  free(head_sorted);
  size = 0; 
  
  while (node) {
    data[size] = node -> data; 
    size++;
    prev = node; 
    node = node -> link;
    free(prev);
  }
  return;
}

int main() {
  int data[1000], i; 
  for (i = 0; i < 1000; i++) {
    data[i] = rand() % 1000;
  }

  InsetionSort(data, 1000);

  for ( i = 0; i <999; i++) {
    if(data[i] > data[ i + 1] )
    {
      puts("Error");
      break;
    }
    printf("%d \n", data[i]);
   }
 return 0;
}
