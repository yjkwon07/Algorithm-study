# 4차시 [Queue] 큐
### 선형 큐
|  <center>연산</center> |  <center>기능</center> | 
|:--------|--------|
|**enQueue(item)** | <center>큐의뒤쪽에 원소를 삽입하는 연산</center> |
|**deQueue()** | <center>큐의 앞쪽에 원소를 삭제하고 반환하는 연산</center> |
|**createQueue()** | <center>공백 상태의 큐를 생상하는 연산</center> |
|**isEmpty()** | <center>큐가 공백상태인지를 확인하는 연산</center> |
|**isFull()** | <center>큐가 포화상태인지를 확인하는 연산</center> |
|**Qpeek()** | <center>큐의 앞쪽에서 원소를 삭제 없이 반환하는 연산</center> |

```c
void enQueue(item){
  if(isFull()) 
    return;
  else {
    rear = rear +1;
    Q[rear] = item;
  }
}

int deQueue() {
  if(isEmpty()) 
    return;
  else {
    front = front+1;
    return Q[front];
  }
}

int isEmpty() {
  if(front == rear)
    return true;
  else 
    return false;
}

int isFull() { 
  if(rear == n-1)
    return true;
  else return false;
}
```

### 원형 큐 삽입 위치 및 삭제 위치 
| |<center>삽입 위치</center> | <center>삭제 위치</center> | 
|--------|--------|-------|
|**<center>선형큐<center>** | <center>rear = rear + 1</center> | <center>front = front + 1</center> |
|**<center>원형큐<center>** | <center>rear = (rear + 1) mod n </center> | <center>front = (front + 1) nod n</center> |
```c
int isEmpty() { 
  if(front = rear) return true;
  else return false;
}

void enQueue(item) {
  if(isFull()) Queue_Full();
  else {
    rear = (rear + 1) mod n; 
    cQ[rear] = item;
   }
}

int deQueue() {
  if(isEmpty()) return;
  else {
    front = (front + 1) mod n;
    return cQ[front];
  }
}

void delete() {
  if(isEmpty()) return
  else front = (front + 1) mod n;
}

int isFull() {
  if((rear + 1) mod n = front ) return true;
  else return false; 
}
```

# 5차시[Queue] 연결 리스트 큐, 우선 순위 큐
### 연결리스트 큐 
```c
void crateLinkedQueue() {
  front  <- null; 
  rear <- null;
}

int isEmpty() {
  if(front = null) return true;
  else return false;
}

void enQueue(item) {
  new <- getNode(); // getNode(): 새로운 노드 할당 후 리턴
  new.data <- item;
  new.link <- NULL;
  if (front = NULL) {
    rear <- new; 
    front <- new;
  }
  else {
    rear.link <- new;
    rear <- new;
  }
}

deQueue() {
  if(isEmpty()) Queue_Empty();
  else {
    old <- front; 
    item <- front.data;
    front <- front.link;
    if (isEmpty()) rear <- NULL;
     free(old);
     return item;
  }
}
```

[대표문제-BFS](https://github.com/yjkwon07/Algorithm-study/blob/master/QUEUE/bfs.cpp)

[미로 찾기](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D4/1226.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%207%EC%9D%BC%EC%B0%A8%20-%20%EB%AF%B8%EB%A1%9C1/SW_1226_sol.java)
