# Algorithm-study
<h1>복잡도 분석</h1>

```
// 1. O(log(n))
while(n)
	n/=2;

// 2. O(sqrt(n))
for(int i=0;i*i<=n;i++);

// 3. O(n)
for(int i=0;i<n;i++);

// 4. O(nlog(n))
for(int i=0;i<n;i++)
	for(int j=i;j;j/=2);

// 5. O(nsqrt(n))
for(int i=0;i<n;i++)
	for(int j=0;j*j<=i;j++);

// 6. O(n^2)
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++);

// 7. O(n^3)
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++);

// 8. O(2^n)
int function(int n){
	if(n==0||n==1)
		return 1;
	return function(n-1)+function(n-2);
}

// 9. O(n!)
// n개의 데이터를 나열하는 방법의 수
void function(int x, vector<int> pick, vector<bool> picked){
	if(x==n){
		for(int i=0;i<pick.size();i++)
			printf("%d\n", pick[i]);
		return;
	}
	for(int i=0;i<n;i++){
		if(picked[i])
			continue;
		pick.push_back(i);
		picked[i]=true;
		function(x+1, pick, picked);
		pick.pop_back();
		picked[i]=false;
	}
	return;
}
```

주어진 순서대로 위가 가장 빠르다.

PS에서 보통 1억을 1초로 잡고 계산한다.

예를 들어 n이 1000이라면 6번 이하로는 가능한 알고리즘이다. 


<h1> 문제 해결 전략 </h1>

공간복잡도는 프로그램의 메모리 사용량을 분석하는 것이다.

간단하게 사용한 배열의 크기 * (해당 자료형의 크기) 로 계산한다. 

보통 기타 지역변수나 헤더파일, 함수, 등을 생각해서 5~10MB 정도는 여유로 빼고 생각한다.

** 평소 생각하던 문제 해결 전략들을 적어나갈 생각이다.



1. x좌표와 y좌표를 분리해서 생각하기

x좌표만 있다고 생각하고 문제를 더 쉽게 풀어보고 이후에 y좌표를 추가하면 어떻게 풀 수 있는지 생각하는 접근 방법이다.



2. 순서를 강제하기

주어진 문제가 임의의 순서를 추가 하였을 때 더 쉽게 접근할 수는 없는지 생각해보는 접근이다.

보통 dp문제에서 많이 사용하는 접근 방법이다.



3. 주어진 문제를 반으로 나누기

주어진 문제를 반으로 나누었을 때 왼쪽 범위에서 시작하고 오른쪽 범위에서 끝나는 답을 비교적 구하기 쉬운지 O(n)
판단하여 분할정복으로 푸는 접근 방법이다.



4. 뒤에서부터 생각하기

보통 앞에서 부터 결정하면 결정하기 난해한 문제들은 뒤에서부터 결정하였을 때 쉽게 풀리는 경우도 있다.



5. 일단 쉬운 알고리즘으로 생각하기

먼저 쉬운 알고리즘으로 접근하여 규칙 또는 최적화가 가능한 부분을 찾고 개선하는 접근 방법이다.



6. 답을 정해놓고 구하는게 더 쉬운지?

임의의 답을 정하고 해당 답이 참인지 거짓인지 판별하는게 더 쉽다면 파라매트릭 서치를 생각해본다.



7. 새로운 공간, 조건, 제약 등을 추가

문제에 없는 새로운 조건이나 제약, 공간등을 추가하고 더 쉬운 문제를 푸는 접근 방법이다.



8. 전처리

알고리즘 중에 미리 계산할 수 있는 부분이 존재하는지 생각해보고 미리 연산하고 저장하고 이용

[출처: 박트리](https://baactree.tistory.com/14)
