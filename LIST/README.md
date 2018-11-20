# 1차시 [List] 리스트

[대표문제-Josephus Problem](https://github.com/yjkwon07/Algorithm-study/blob/master/LIST/Josephus%20Problem.cpp)

## 비효율적 연산
위의 코드는 한 칸씩 이동 횟수를 세며 k번째에 해당하는 이동 횟수에 해당 배열을 삭제한 전략을 선택하였다.

그러나 과연 이 방법이 효율적일까? 그렇지 않다. 사실, 이 코드의 경우 사람의 숫자가 많아질수록 k의 값이 커질수록 불필요한 연산이 계속해서 증가하게 된다.

따라서 올바른 결과를 출력하는데는 문제가 없는 코드이지만, 효율적인 코드는 아니다. 

## 리스트 
  - 순서를 가진 데이터의 집합을 가리키는 추상 자료 형이라 하는데, 동일한 데이터를 가지고 있어도 상관이 없다.
  - 한가지 고려해야 할 점은 구현 방법에 따라 순차 리스트와 연셜 리스트로 나뉘어 지는데
  - 순차 리스트는 배열을 기반으로 구현된 리스트
  - 연결 리스트는 메모리의 동적 할당을 기반으로 구현된 리스트를 말한다. 
  
  ### 연산
  - 리스트 앞쪽의 원소를 추가하는 연산
  - 리스트 뒤쪽에 원소를 추가하는 연산
  - 또 추가한 원소들 중에 하나의 원소를 삭제하는 연산
  - 특정한 위치에 있는 원소를 리턴하는 연산 
  
## 연결 리스트 
```c
strcut NODE {
  char data;
  NODE * prev, *next;
};

void add_node(NODE * prev_node, char val) {

  // 메모리를 할당하여 새로운 노드 new를 생성
  NODE * p_new = (NODE *)malloc(sizeof(NODE));
  NODE * p_next = prev_node -> next;
  
  // 새로운 노드 new의 데이터 필드에 데이터를 저장
  p_new -> data = val;
  
  // 삽입될 위치의 바로 앞에 위치한 노드의 링크 필드를 p_new의 링크 필드에 복사
  p_new->next = p_next;
  
  // p_new의 주소를 앞 노드의 일크 필드에 저장
  prev_node -> next = p_new;
  
  // p_new의 prev에 앞에 위치한 노드 주소를 저장한다.
  p_new -> prev = prev_node;
  
  // 뒤 노드의 prev에 p_new 노드의 주소를 저장한다.
  p_next -> prev = p_new;
}

void delete_node(NODE * prev) {
  // 삭제할 노드의 앞 노드(선형 노드) 탐색
  NODE * target_node = prev -> link;
  
  // 삭제할 노드의 링크 필드를 선행 노드의 링크 필드에 복사
  prev -> link = target_node -> link;
  
  // 더이상 접근 방법이 없어진 target_node 삭제
  free(target_node);
}
```

# 삽입 정렬 
## Q 삽입 정렬 
  - 오름차순 삽입정렬 함수 InsertionSort를 구현하고, 주어진 main 함수로 검증해 보자. 
  단, 함수의 인자 값은 변해도 상관없다.
  
  [삽입 정렬](https://github.com/yjkwon07/Algorithm-study/blob/master/LIST/%EC%82%BD%EC%9E%85%EC%A0%95%EB%A0%AC.cpp)

## 병합 정렬

  - 자료를 최소 단위의 문제까지 나눈 후에 차례대로 정렬하여 결과를 얻어내는 Top-Down 방식이라고 말할 수 있다.
  
### Q 오름차순 병합정렬 함수인 MergeSort를 구현하고 주어진 main함수를 통해 검증해 보자. 단, 함수의 인자 값은 변해도 상관없다.

[병합정렬](https://github.com/yjkwon07/Algorithm-study/blob/master/LIST/%EB%B3%91%ED%95%A9%EC%A0%95%EB%A0%AC.cpp)

# 횐형 리스트
[대표문제-Josephus Problem](https://github.com/yjkwon07/Algorithm-study/blob/master/LIST/Josephus%20Problem%20-list.cpp)

사실, 위에서 배운 리스트를 통해 스택과 큐를 구현할 수도 있는데, 기본적인 원리는 같지만, 메모리를 더 효율적으로 쓸 수 있다는 접과 우선순위 큐를 효울적으로 구현할 수 있다는 점이 다른데,
우선순위 큐는 원스를 삽입하는 과정에서 우선순위를 비교하여 적절한 위체 삽입하는 구조로 이루어져 있다. 이러한 자료구조를 배열로 구현한다면 어떻게 될까?
메모리 낭비뿐만 아니라 소요되는 시간이나 메모리 낭비가 크기 때문에 연결 리스트를 통해 구현하는 경우가 많다.

