# 1차시 [Stack] 스택, 후위 표기법 
```c
int stack[size];
int top;

void push(int input)
{
  stack[top++] = input;
}

void pop(int * output)
{
  output = stack[--top];
}
```
## Q 같은 번호 짝 소거하기 

### stack을 사용하지 않을 때 O(n^2)
```c
scanf("%s", str);
is_change = 1;

while(is_change) {
  is_change = 0;
  
  // 문자열의 끝까지 검사
  for( i = 0;  str[ i + 1 ]; i++) {
    if(str[i] == str[i+1] ) // 인접한 문자열이 같은 경우
      is_change = 1;
    if(is_change) // 같은 숫자가 있는 경우 뒤에 있는 숫자를 이동 시킨다.
      for( int i = 1; str[i+1]; i++)
        str[i] = str[i+2];
  }
}
```
### stack 사용 O(n)
```c
scanf("%s", str); 
stack[0] = str[0];
top = 1; 
for(i = 1; str[ i- 1]; i++) {
  if(top != 0 && stack[pop- 1] == str[i] )
    top--;
  else
    stack[top++] = str[i];
}

printf("%s\n", stack);
```


[괄호 검사](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%EA%B4%84%ED%98%B8%20%EA%B2%80%EC%82%AC.cpp)

[대표문제-계산기](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/calculation.cpp)

[계산기](https://github.com/yjkwon07/Algorithm-study/blob/master/SW%EB%AC%B8%EC%A0%9C/D4/1222.%20%5BSW%20%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%20%EA%B8%B0%EB%B3%B8%5D%206%EC%9D%BC%EC%B0%A8%20-%20%EA%B3%84%EC%82%B0%EA%B8%B01/SW_1222.java)

# 2차시 [Stack] 깊이 우선 탐색, 백트래킹 기법
## 깊이 우선 탐색 
  - DFS는 비선형 구조인 그래프 구조에서 그래프 형태로 표현된 모든 자료를 빠짐 없이 검색하는 하나의 방법
  - 시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 탐색해 가다가 더 이상 갈 곳이 없게 되면, 
    가장 마지막에 만났던 갈림길 간선이 있는 정점으로 돌아와서 다른 방향의 정점으로 탐색을 계속 반복하여 
    결국, 모든 정점을 방문하는 순회 방법이다.
    
[노드 순회](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%EB%85%B8%EB%93%9C%EC%97%B0%EA%B2%B0%20-dfs.cpp)

[대표문제-미로찾기- dfs](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%EB%AF%B8%EB%A1%9C%EC%B0%BE%EA%B8%B0%20-dfs.cpp)

## 백트래킹 기법
  - 이 기법을 통해 최적화(Optimization)문제와 결정(Decisin)문제를 해결할 수 있다. 
   다시 말해서, DFS에서 발전한 기법이 Backtracking이다.
  - 기본적으로 DFS를 사용하여 탐색 중에 오답을 만나면 이전 분기점으로 돌아가며, 시도해보지 않은 다른 해결
    방법이 있으면 시도한다. 해결 방법이 더 없으면 이전 분기점으로 이동하낟. 만일, 모든 경우를 다 검사했을 경우에도
    답을 찾지 못한경우는 이 문제의 해결책은 없는것이라고 판별할 수 있다.
  - 메모리공간은 덜 차지하는데, 이는 현재의 상태를 보관하고 바꾸는 동안만 차지하기 때문이다. 뿐만 아니라,
    더 이상 해가 나올 가능성이 없는 부분에 대해서는 더 이상 탐색하지 않도록 설계하는데, 이를 Pruning(가지치기)이라고 한다.

[가지치기](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/backtracking%20-dfs.cpp)

[power-set](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/power%20set%20-backtrack.cpp)

[순열](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%EC%88%9C%EC%97%B4%20-backtrack.cpp)

[미로찾기 -stack](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%EB%AF%B8%EB%A1%9C%EC%B0%BE%EA%B8%B0%20-stack.cpp)

# 3차시[Stack] 최적의 해 solution

### recursive
  - 함수를 재귀적으로 호출하여 풀 수있게 된다. 
  - 재귀적으로 함수를 호출 할 경우 낭비되는 메모리 생긴다.
  - 이런 중복연산을 최소화 하기 위해 미리 메모리에 저장하는 방법을 Memoization이라고 한다.

[피보나치 수열 recursive](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20%20-recursive.cpp)

### DP solution: O(n)
  - Memoization은 컴퓨터 프로그램을 실행할 때 이전에 계산한 값을 메모리에 저장해서 매번 
    다시 계사하지 않도록 하여 전체적인 실행속도를 빠르게 하는 기술이다. 
    DP의 핵심 기술이 되기도 하는데 이 계획법은 그리디 알고리즘과 같이 최적화 문제를 해결하는 AL이다.

  - 좀 더 자세히 설명하자면, 먼저 입력 크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용하여 
    보다 큰 크기의 부분 문제들을 해결함으로써, 최종적으로 원래 두어진 입려의 문제를 해결하는 AL이라고 표현 할 수 있다.
    DP은 Optimal Substructure인 경우와 Overlapping Recursive Calls인 경우 사용하는데,
  
  - optimal Substructure은 큰 문제의 최적 솔루션에 작은 문제의 최적 솔루션이 포함되는 경우
    Overlapping Recursive Calls는재귀적 해법으로 풀면 같은 문제에 대한 재귀호출이 심각하게 중복되는 경우 
    두 요건이 충족되는 경우 동적 계획법이 좋은 해결법으로 사용되고 있다. 

  - 동적 계획법 기반의 알고리즘 전략은 문제를 부분 문제로 나누고, 가장 작은 부분붑터 해를 구하여 테이블에 저장하며,
    이 테이블의 값을 사용하여 좀더 큰 부분의 해를 구하고, 이를 반복하여 마지막 해를 구하는데 이를 Bottom-Up(상향식 방법)
    이라 부르기도 한다. 
이러한 방법이 재귀적 호출보다 뛰어난 이유는 재귀적 호출 자체가 내부 시스템 호출 Stack을 사요하는 오버헤드가
발생하는데, 반대로 동적 계획법을 사용한 경우 이러한 오버헤드가 발생하지 않기 때문이다.

[대표문제-피보나치 수열 DP](https://github.com/yjkwon07/Algorithm-study/blob/master/STACK/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20-DP.cpp)
