#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct NODE {
  int data; 
  NODE *link;
};

// 병합
NODE * Merge(NODE * left, NODE * right) {
  NODE * node = (NODE *)malloc(sizeof(NODE)); // 임시 head 생성
  NODE * head = node;
 
  while (left && right) {
    // 왼쪽 리스트와 오른쪽 리스트 중 현재 값이 더 작은 값을 node에 붙이다.
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
   // 남아있는 리스트들 뒤에 만들어진 노드 뒤에 붙인다. 
   if(left) {
    node -> link = left;
   }
   else {
    node -> link = right;
   }
   
   node = head -> link; 
   // 임시 head 제거
   free(head);
   return node;
 }
 // 분할
 NODE * Devide(NODE * first, int size) {
  int i;
  NODE * left = first;
  NODE * right = first;
  NODE *prev_right = first;
  
  // 리스트중 가운데 원소를 찾는다.
  for ( i = 0; i < (size /2) - 1; i++) {
    prev_right = prev_right -> link;
  }
  right = prev_right -> link;
  //왼쪽의 마지막 원소의 link를 아무것도 가리키지 않는 상태로 바꾼다. 
  prev_right -> link = NULL;
  
  // 원소의 크기가 1이상일 경우에 대해 분할을 다시한다.
  if(size/2>1) left = Devide(left, size / 2);
  if(size - (size / 2) > 1) right = Devide(right, size - (size / 2) );
  
  // 왼쪽과 오른쪽을 합친 값을 return 한다.
  return Merge(left, right);
}

void MergeSort(int data[], int size) {
  int i;
  // 정렬되지 않은 집합(head)에 기존 데이터를 대입한다.
  NODE *head_unsorted = (NODE *)malloc(sizeof(NODE));// 정렬되지 않은 집합 생성 (head)
  NODE * node = head_unsorted;
  
  head_unsorted -> link = NULL;
  
  for (i = 0; i < size; i++) {
    node -> link = (NODE *)malloc(sizeof(NODE));
    node = node -> link;
    node -> data = data[i];
    node -> link = NULL;
  }
  
  // 병합정렬 시작
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
