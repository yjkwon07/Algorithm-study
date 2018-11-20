#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct NODE {
  int data; 
  NODE *link;
};

// ����
NODE * Merge(NODE * left, NODE * right) {
  NODE * node = (NODE *)malloc(sizeof(NODE)); // �ӽ� head ����
  NODE * head = node;
 
  while (left && right) {
    // ���� ����Ʈ�� ������ ����Ʈ �� ���� ���� �� ���� ���� node�� ���̴�.
    if(left ->data < right -> data)
    {
      node -> link = left;
      left = left -> link;
      node = node -> link;
    }
    else
    {
      node -> link = right;
      right = right -> link;
      node = node -> link;
    }
   }
   // �����ִ� ����Ʈ�� �ڿ� ������� ��� �ڿ� ���δ�. 
   if(left) {
    node -> link = left;
   }
   else {
    node -> link = right;
   }
   
   node = head -> link; 
   // �ӽ� head ����
   free(head);
   return node;
 }
 // ����
 NODE * Devide(NODE * first, int size) {
  int i;
  NODE * left = first;
  NODE * right = first;
  NODE *prev_right = first;
  
  // ����Ʈ�� ��� ���Ҹ� ã�´�.
  for ( i = 0; i < (size /2) - 1; i++) {
    prev_right = prev_right -> link;
  }
  right = prev_right -> link;
  //������ ������ ������ link�� �ƹ��͵� ����Ű�� �ʴ� ���·� �ٲ۴�. 
  prev_right -> link = NULL;
  
  // ������ ũ�Ⱑ 1�̻��� ��쿡 ���� ������ �ٽ��Ѵ�.
  if(size/2>1) left = Devide(left, size / 2);
  if(size - (size / 2) > 1) right = Devide(right, size - (size / 2) );
  
  // ���ʰ� �������� ��ģ ���� return �Ѵ�.
  return Merge(left, right);
}

void MergeSort(int data[], int size) {
  int i;
  // ���ĵ��� ���� ����(head)�� ���� �����͸� �����Ѵ�.
  NODE *head_unsorted = (NODE *)malloc(sizeof(NODE));// ���ĵ��� ���� ���� ���� (head)
  NODE * node = head_unsorted;
  
  head_unsorted -> link = NULL;
  
  for (i = 0; i < size; i++) {
    node -> link = (NODE *)malloc(sizeof(NODE));
    node = node -> link;
    node -> data = data[i];
    node -> link = NULL;
  }
  
  // �������� ����
  node = Devide(head_unsorted -> link , size);
  
  free(head_unsorted);
  
  for(i=0; i < size; i++) {
    data[i] = node -> data;
    node = node -> link;
  }
  
  return;
}

int main() {
  int data[1000], i;
  for (i = 0; i < 1000; i++) {
    data[i] = rand() % 1000;
  }
  
  MergeSort(data, 1000);
  
  for(i = 0; i < 999; i++) {
    if (data[i] > data[i+1])
    {
      puts("Error");
      break;
    }
      printf("%d \n",data[i]);
  }

  return 0;
}
