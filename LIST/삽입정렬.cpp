#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

struct NODE {
  int data; 
  NODE *link;
};

void add_node(NODE * prev, NODE * p_new) {
  // ���Ե� ��ġ�� �ٷ� �տ� ��ġ�� ����� ��ũ �ʵ带 p_new�� ��ũ �ʵ忡 ���� 
  p_new -> link = prev -> link;
  
  // p_new�� �ּҸ� �� ����� ��ũ �ʵ忡 ����
  prev -> link = p_new; 
}

NODE * delete_node(NODE *prev) {
  // ������ ����� �� ���(���� ���) Ž�� 
  NODE * target_node = prev ->  link;
  
  // ������ ����� ��ũ �ʵ带 ���� ����� ��ũ �ʵ忡 ���� 
  prev -> link = target_node -> link;
  
  // ���̻� ���� ��� ������ target_node ���� 
  target_node -> link = NULL;
  return target_node;
}

void InsetionSort(int data[], int size) {
  int i;
  // ���ĵ��� ���� ����(head)�� ���� �����͸� �����Ѵ�. 
  NODE *head_unsorted = (NODE *)malloc(sizeof(NODE)); // ���ĵ��� ���� ���� ���� (head)
  NODE *head_sorted = (NODE *)malloc(sizeof(NODE)); // ���ĵ� ���� ���� (head)
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
  
  // ���ĵ��� ���� ������ �������� �ɶ� ���� 
  while (head_unsorted -> link) {
    // ���ĵ��� ���� ������ ù��° ���Ҹ� ������ 
    node = delete_node(head_unsorted);
    
    // ���ĵ� ���տ��� �ڽź��� ū ���Ҿտ� �ִ´�.
    prev = head_sorted;
    curr = head_sorted -> link;
    while( curr && curr -> data < node -> data) {
      prev = prev -> link;
      curr = curr -> link; 
    }
    add_node(prev, node);
  }
  free(head_unsorted);
  // �ٽ� ���ĵ� ������ ������ data �迭�� ���� 
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
