[모든 정렬 과정](https://www.toptal.com/developers/sorting-algorithms)

[STL_study](https://github.com/yjkwon07/Algorithm-study/blob/master/%EC%A0%95%EB%A0%AC/STL.md)

# 선택 정렬
## O(N^2)
가장 작은 것을 선택해서 제일 앞으로 보내는 알고리즘 

```c
#include <stdio.h>

int main(void) {
	int i , j, min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for( i =0; i <10; i++) {
		min = 9999;
		for(j = i; j <10; j++) {
			if(min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i = 0; i <10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
```

# 버블 정렬
## O(N^2)
가까이에 있는 두 숫자끼리 비교를 해서 당장 더 작은 숫자를 앞으로 보내주는 알고리즘

옆에 있는 값과 비교하여 더 작은 값을 반복적으로 앞으로 보내는 정렬 방법

`가장 비효율적인 알고리즘`

```c
#include <stdio.h>

int main (void) {
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 8, 4, 3, 2, 9};
	for( i = 0; i < 10; i++) {
		for(j =0; j <9 - i; j++) {
			if(array[j] > array[j + 1]) {
				temp = array[j];
				array[i] = array[j+1];
				array[j +1] = temp;
			}
		}
	}
	for(i =0; i < 10; i++1) {
		printf("%d ", array[i]);
	}
	return 0;
}
```

# 카운팅 정렬
## O(n + k)
 Counting Sort이란 항목들의 순서를 결정하기 위해 집하에 각 항목이 몇 개씩 있는지 세는 작업을 하여, 선형 시간에 정렬하는 효율적인 알고리즘이다. n은 리스트 길이, k는 정수의 최대값이라 하면, 시간 복잡도는 O(n + k)이다. 카운팅 정렬은 버블정렬과는 달리 교환하지 않는 방식을 사용한다. 이 정렬은 __n이 비교적 적을 때만 가능하다.__ 는 것을 알아두자. 
 
 카운팅 정령의 특징은 다음과 같다. 정수나 정수로 표현할 수 잇는 자료에 대해서만 적용 가능하다. 각 항목의 발생 횟수를 기록하기 위해, 정수 항목으로 인덱스 되는 카운트들의 배열을 사용하기 때문이다. 카운트들을 위한 충분한 공간을 할당하려면 집합 내의 가장 큰 정수를 알아야 한다. 속도가 빠르며 안정적이다. 
 ```
 // 각 항목들 발생 횟수 세기
 for(int i = 0; i < size; i++) {
 	if (maxValue < data[i]) maxValue = data[i];
	counts[data[i]]++;
}
// 각 항목 위치 설정을 위한 카운트 조정
for(int i = 1; i <= maxValue; i++) {
	counts[i] = counts[i] + counts[ i - 1];
}
// 카운트를 사용하여 각 항목 위치 결정 
for (int i = size - 1; i >= 0; i--) {
	temp[--counts[data[i]] = data[i];
}
 ```
 
# 삽입 정렬
## O(N^2)
각 숫자를 적절한 위치에 삽입하는 방법

`필요할 때만` 위치를 바꾼다. 

삽입 정렬은 `정렬이 되어있다고 가정`을 한다는 점에서 특정한 경우에 따라 굉장히 빠른 속도를 자랑 

데이터가 이미 거의 정렬된 상태에서 한해서는 어떤 알고리즘보다도 빠르다는 특징


```c 
#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array [10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i =0; i <9; i++) {
		j = i; 
		while( j >= 0 && array[j] > array[j +1]) {
			temp = array[j];
			array[j] = array[j +1];
			array[j +1] = temp;
			j--;
		}
	}
	for(i = 0; i <10; i++) {
		printf("%d ",array[i] );
	}
	return 0; 
}
```

# 퀵 정렬 
## O(N*logN)
## 최악 O(N^2) 거의 정렬된 배열
대표적인 `분할 정복`알고리즘

특정한 값을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눈다.

[퀵 소트 과정](http://yujuwon.tistory.com/entry/%ED%80%B5-%EC%A0%95%EB%A0%AC)

```c
#include <stdio. h>

int number = 10; 
int data [] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void show() { 
  int i;
  for(i = 0; i < number; i++) {
      printf("%d ", data[i]);
  }
}

void quickSort(int * data, int start, int end) {
    if(start >= end) { // 원소가 1개인 경우 그대로 두기
        return;
    }
    
    int key = start; // 키는 첫 번째 원소
    int i = start + 1, j = end, temp;
    
    while( i <= j) { // 엇갈릴 때까지 반복 
      while(i <= end && data[i] <= data[key]) { // 키 값보다 큰 값을 만날 때 까지 
        i++;
      }
      
      while( j > start && data[j] >= data[key]) { // 키 값보다 작은 값을 만날 때 까지
        j--;
      }
      
      if(i > j ) { // 현재 엇갈린 상태면 키 값과 교체 
        temp = data[j]; 
        data[j] = data[key];
        data[key] = temp;
      }
      else { // 엇갈리지 않았다면 i와 j를 교체 
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        }
    }
    
    quickSort(data, start, j - 1);
    quickSort(data, j +1, end);
}

int main(void) { 
  qucikSort(data, 0, number -1);
  show();
  return 0;
}
```


# 병합 정렬(Merge Sort)
## O(N*logN)
병합 정렬도 대표적인 `분할 정복`방법을 채택한 알고리즘

`최악인 경우에도 O(N*logN)을 보장`

하나의 큰 문제를 두 개의 작은 문제로 분할한 뒤에 각자 계산하고 나중에 합치는 방법을 채택 

`일단 정확히 반으로 나누고 나중에 정렬`

`합치는 순간에 정렬을 수행`

[정렬 과정](https://blog.naver.com/ndb796/221227934987)

알고리즘을 구현할 때 신경써야 하는 부분은 반드시 정렬에 사용되는 배열은 `전역 변수`로 선언 해야한다. 

만약 함수 안에서 배열을 선언하게 된다면 매 번 배열을 선언해야 한다는 점에서 메모리 자원의 낭비가 매우 커질수 있다.

따라서 병합정렬은 `기존의 데이터를 담을 추가적인 배열 공간이 필요하다`점에서 메모리 활용이 비효율적이다.

```c
#include<stdio.h>
int number = 8;

int size; 
int sotred[8]; // 정렬 배열은 반드시 전역 변수로 선언
int count = 0;

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle +1;
	int k = m;
	
	// 작은 순서대로 배열에 삽입
	while(i <= middle && j <= n) {
		if(a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	} 
	
	// 남은 데이터도 삽입 
	if( i > middle) {
		for( int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} 
	else {
		for(int t= i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	
	// 정렬된 배열을 삽입
	for(int t =m; t<= n; t++) {
		a[t] = sorted[t];
	} 
} 

void mergeSort(int a[], int m, int n) {
	// 이외의 경우는 크기가 1개인 경우
	if(m < n) {
		int middle = (m + n) /2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	} 
}

int main (void) {
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number -1);
	for(int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
}

```

# 힙정렬
실제로 고급 프로그래밍 기법으로 갈 수록 힙의 개념이 자주 등장하기 때문에 반드시 알아야한다. 

힙정렬은 `힙 트리 구조를 이용하는 정렬 방법이다`

힙 정렬을 수행하기 위해서는 __힙 생성 알고리즘(Heap AL)을 사용한다.__

`하나의 노드를 제외하고는 최대 힙이 구성되어 있는 상태`라고 가정을 한다. 

힙 생성 알고리즘이란 `특정한 노드의 두 자식 중에성 더 큰 자식과 자신의 위치를 바꾸는 알고리즘이다.`

힙 생성 알고리즘: O(log N)

전체 데이터의 갯수가 N개이므로 시간복잡도 O(N * logN)

힙 구조를 만드는 복잡도 O(N)

(정확히는 모든 데이터를 기준으로 힙 생성 알고리즘을 쓰지 않아도 되기 때문에 O(N)으로 끝낼 수 있다)

한 마디로 전체 __힙 정렬의 전체 시간 복잡도는 O(N * logN + N) = O(N * logN)__

```c
#include <stdio.h>

int number= 9; 
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6};

int main (void) {
	// 힙을 구성 
	for(int i= 1; i<number; i++)  {
		int c = i;
		do {
			int root = (c-1) / 2; 
			if(heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while(c != 0);
	}
	
	// 크기를 줄여가며 반복적으로 힙을 구현
	for(int i = number -1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root =0;
		int c= 1; 
		do {
			c =2 * root +1; 
			// 자식 중에 더 큰 값을 찾기
			if( c < i -1 && heap[c] < heap[c +1]) {
				c++;
			} 
			// 루트보다 자식이 크다면 교환
			if(c <i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] =temp;
			}
			root = c;
		} while (c < i);
	} 
	// 결과 출력
	for(int i = 0; i < number; i++) {
		printf("%d", heap[i]);
	} 
}
```

### 힙 정렬은 병합 과정과 다르게 별도로 추가적인 배열이 필요하지 않다
`메모리 측면에서 몹시 효율적`

`항상 O(N * logN)을 보장`

최대 힙을 활용한 오름차순 정렬에서 힙 생성 합수는 특정한 노드를 기준으로 `위쪽으로 올라가는` __상향식 구셩 방식__ 과 `아래쪽으로 내려가는` __하향식 구현 방식__ 이 있다. 

위 본문은 상향식 방법이다. 

아래부터는 하향식 방법이다. 

```c
#include <iostream>
#include <vector>

using namespace std;

int number; 
int heap[1000001];

void heapify(int i) {
	//왼쪽 자식 노드를 가리킵니다.
	int c = 2 * i + 1;
	// 오른쪽 자식 노드가 있고, 왼쪽 자식노드보다 크다면 
	if(c < number && heap[c] < heap[c + 1]) {
		c++;
	} 
	// 부모보다 자식이 더 크다면 위치를 교환
	if(heap[i] < heap[c]) {
		int temp = heap[i];
		heap[i] = heap[c];
		heap[c] = temp;
	} 
	// number / 2까지만 수행하면 된다.
	if(c <= number / 2) heapify(c); 
}

int main(void) {
	cin >> number; 
	for(int i = 0; i < number; i++) {
		int x;
		cin >> heap[i];
	}
	//힙을 생성 
	for(int i = number /2; i>= 0; i--) {
		heapify(i);
	}
	// 정렬을 수행합니다.
	for(int i = number -1; i >= 0; i--) {
		for(int j =0; j < number; j++) {
			cout << heap[j] << ' ';
		}
		cout << '\n';
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if(c < i - 1 && heap[c] < heap[c + 1]) c++;
			if(c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while(c < i);
	} 
}
```

 
