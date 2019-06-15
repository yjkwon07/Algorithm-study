# 1차시 [Array] 배열
[대표문제-Gravity -> O(n^3) ](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/Gravity.cpp)

[대표문제-Gravity -> O(n^2) ](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/Gravity2.cpp)

# 2차시 [Array] 순열, 정렬
- `Exhaustive search(완전 검색)` -> input이 작을 때 (모든 경우의 수 나열)
  - `Brute - Force` (동의어)
  - `Generate - And - Test` (동의어)
- `Greedy - AL`

  선택할 수 있는 여러 경우 중 하나를 선택할 때 가장 최적이라고 생각되는 것을 선택해 나가는 방식으로 진행하여 최종적인 해답에 도달하는 방법 
  각 선택의 시점에서 이루어지는 결정은 지역적으로는 최적이지만, 그 선택들을 통해 최종적인 해답을 만들었다고 해서 그것이 최적이라는 보장이 없는 계획법이다.
  일반적으로 머리 속에 떠오르는 생각을 검증 없이 바로 구현할 경우 탐욕 알고즘적인 접근이 되는 경우가 있다. (동전 거스름돈)

[정렬](https://github.com/yjkwon07/Algorithm-study/tree/master/%EC%A0%95%EB%A0%AC)

[대표문제-Baby Gin Game](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/Baby%20Gin.cpp)

# 3차시 [Array] 비트 연산자, 검색
[부분집합](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/%EB%B6%80%EB%B6%84%EC%A7%91%ED%95%A9.cpp)

[대표문제-집합의 합 해결하기](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/%EB%B9%84%ED%8A%B8%20%EB%B6%80%EB%B6%84%EC%A7%91%ED%95%A9.cpp)

[비트연산 -D5](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D5/1242.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EC%9D%91%EC%9A%A9%5D%201%EC%9D%BC%EC%B0%A8%20-%20%EC%95%94%ED%98%B8%EC%BD%94%EB%93%9C%20%EC%8A%A4%EC%BA%94/number20_sol.java)

- 검색
  - `(순차 검색) Sequential search`
  
  정렬되어 있지 않은 경우와 정렬되어 있는 경우의 성능차이는 다르다.
  
  ```
  // *ar: 자료 
  // num: 자료의 사이즈 
  // key: 찾고자 하는 숫자 
  int sequentialSearch(int *ar, unsigned int num, int key)
  { 
    unsigned int i;
    // 자료의 처음부터 끝가지 반복
    for(i = 0; i < num; i++)
    {
      // 숫자가 존재할 경우
      if(ar[i] == key)
      { 
        return i;
      }
    }
    retrun -1;
  }  
  ```
  
  - `(이진 검색) Binary search`
  
  .
  
  ```
  int binarySearch(int *ar, int num, int key)
  {
    int up. down, mid;
    
    down = 0;
    up = num - 1;
    for(;;) {
     // 중앙 원소
     mid = (up + down) / 2;
     
     if(ar[mid] == key) return mid;
     // 목표 값이 원소보다 작다면 왼쪽 반 수행
     if(ar[mid] > key) {
      up = mid - 1; 
     }
     else {
      down = mid + 1;
     }
     // 검색이 끝남
     if(up < down) {
      return -1;
     }
    }
  }
  ```
  - `(해쉬 검색) Hash`
  - `index` 
  
# 4차시 [Array] 배열의 순회, 선택 정렬
[자신의 위칫값 차의 합](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/%EC%9E%90%EC%8B%A0%EC%9D%98%20%EC%9C%84%EC%B9%AB%EA%B0%92%20%EC%B0%A8%EC%9D%98%20%ED%95%A9.cpp)

[달팽이 순회](https://github.com/yjkwon07/Algorithm-study/blob/master/ARRAY/%EB%8B%AC%ED%8C%BD%EC%9D%B4%20%EC%88%9C%ED%9A%8C.cpp)

[대표문제-Ladder](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D4/1210.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%202%EC%9D%BC%EC%B0%A8%20-%20Ladder1/SW_1210_sol.java)

# 5차시 [Array] 
[대표문제-평탄화 해결하기](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D3/1208.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%201%EC%9D%BC%EC%B0%A8%20-%20Flatten/SW_1208_sol.c.txt)

# 문제
[1204.[S/W 문제해결 기본] 1일차 - 최빈수 구하기](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D3/1204.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%201%EC%9D%BC%EC%B0%A8%20-%20%EC%B5%9C%EB%B9%88%EC%88%98%20%EA%B5%AC%ED%95%98%EA%B8%B0/SW_1204.java)

[1206.[S/W 문제해결 기본] 1일차 - View](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D3/1206.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%201%EC%9D%BC%EC%B0%A8%20-%20View/SW_1206.java)

[1208. [S/W 문제해결 기본] 1일차 - Flatten](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D3/1208.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%201%EC%9D%BC%EC%B0%A8%20-%20Flatten/SW_1208.java)

[1209. [S/W 문제해결 기본] 2일차 - Sum](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D3/1209.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%202%EC%9D%BC%EC%B0%A8%20-%20Sum/SW_1209.java)

[1210. [S/W 문제해결 기본] 2일차 - Ladder1](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D4/1210.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%202%EC%9D%BC%EC%B0%A8%20-%20Ladder1/SW_1210_sol.java)

[1211. [S/W 문제해결 기본] 2일차 - Ladder2](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D4/1211.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%202%EC%9D%BC%EC%B0%A8%20-%20Ladder2/SW_1211_sol.java)
