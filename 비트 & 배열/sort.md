[모든 정렬 과정](https://www.toptal.com/developers/sorting-algorithms)
# 1. 선택 정렬
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

# 2. 버블 정렬
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
		for(j =0; j <9 -1; j++) {
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

# 3. 삽입 정렬
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

# 4. 퀵 정렬 
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


# 5. 병합 정렬(Merge Sort)
## O(N*logN)
병합 정렬도 대표적인 `분할 정복`방법을 채택한 알고리즘

`최악인 경우에도 O(N*logN)을 보장`

하나의 큰 문제를 두 개의 작은 문제로 분할한 뒤에 각자 계산하고 나중에 합치는 방법을 채택 

`일단 정확히 반으로 나누고 나중에 정렬`

`합치는 순간에 정렬을 수행`

[정렬 과정](https://blog.naver.com/ndb796/221227934987)

알고리즘을 구현할 때 신경써야 하는 부분은 반드시 정령에 사용되는 배열은 `전역 변수`로 선언 해야한다. 

만약 함수 안에서 배열을 선언하게 된다면 매 번 배열을 선언해야 한다는 점에서 메모리 자원의 낭비가 매우 커질수 있다.

따라서 병합정렬은 `기존의 데이터를 담을 추가적인 배열 공간이 필요하다`점에서 메모리 활용이 비효율적이다.

```c
#include<stdio.h>
int number = 8;

int size; 
int sotred[8]; // 정렬 배열은 반드시 전역 변수로 선언
nt count = 0;

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
		mergeSort(a, m, middle, n);
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



